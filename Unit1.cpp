//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int n,range,Max_range,Max_num;
int **Edge;
int **Edge2;
int *use,*mask,*mst;
int v,ln;
clock_t t1,t2,t3;


void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}
void GenerateMatrix(int flag) {
	if(flag == 1) {
		if(Edge != NULL) {
			for(int i = 0;i < ln;i++) {
				delete[] Edge[i];
			}
			delete[] Edge;
		}
		Edge = new int*[n];
		for(int i = 0;i < n;i++) {
			Edge[i] = new int[n];
		}
		Form1->StringGrid1->RowCount = n;
		Form1->StringGrid1->ColCount = n;
	}
	else if(flag == 2) {
		v = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				if(Edge[i][j] != Max_num) {
					v++;
				}
			}
		}
		Edge2 = new int*[v];
		for(int i = 0;i < v;i++) {
			Edge2[i] = new int[3];
		}
		for(int i = 0,k = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				if(Edge[i][j] != Max_num) {
					Edge2[k][0] = i;
					Edge2[k][1] = j;
					Edge2[k++][2] = Edge[i][j];
				}
			}
		}

		for(int i = 0,min = 0; i < v; i++,min = i) {
			for(int j = i+1; j < v; j++) {
				if(Edge2[min][2] > Edge2[j][2]) {
					min = j;
				}
			}
			swap(Edge2[i][0],Edge2[min][0]);
			swap(Edge2[i][1],Edge2[min][1]);
			swap(Edge2[i][2],Edge2[min][2]);
		}
		Form1->StringGrid2->RowCount = v;
		Form1->StringGrid2->ColCount = 3;
	}
	else if(flag == 3) {
		mst = new int[n-1];
		for(int i = 0; i < n-1; i++) {
			mst[i] = -1;
		}
	}
	else if(flag == 4) {
		use = new int[v];
		for(int i = 0; i < v; i++) {
			use[i] = 0;
		}
	}
	else if(flag == 5) {
		mask = new int[v];
		for(int i = 0; i < v; i++) {
			mask[i] = i;
		}
	}
}


void create() {
	int a;
	GenerateMatrix(1);
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			a = rand()%range+1;
			Edge[i][j] = a > Max_range ? Max_num:a;
			Edge[j][i] = Edge[i][j];
		}
		Edge[i][i] = Max_num;
	}
	GenerateMatrix(2);
}


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	n = StrToInt(Edit1->Text);
	range = StrToInt(Edit2->Text);
	Max_range = StrToInt(Edit3->Text);
	Max_num = StrToInt(Edit4->Text);
	create();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			Form1->StringGrid1->Cells[j][i] = Edge[i][j];
		}
	}
	ln = n;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	FILE *fp;
	AnsiString out;
	if (OpenDialog1->Execute()) {
		out = OpenDialog1->FileName;
		fp = fopen(out.c_str(), "r+");
		fscanf(fp, "%d %d %d %d", &n, &range, &Max_range, &Max_num);
		Edit1->Text = n;
		Edit2->Text = range;
		Edit3->Text = Max_range;
		Edit4->Text = Max_num;
		GenerateMatrix(1);
		ln = n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				fscanf(fp, "%d", &Edge[i][j]);
			}
		}
		GenerateMatrix(2);
		fclose(fp);
	}
	else  Memo1->Lines->Add("Nothing happened...");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	int edge = 0,cycle = 0,large = 0,small = 0,sum = 0,min = 0;
	int u,v;
	GenerateMatrix(3);
	GenerateMatrix(4);
	GenerateMatrix(5);
	t1 = clock();
	while (edge < n-1) {
		use[min] = 1;
		u = Edge2[min][0];
		v = Edge2[min][1];
		if(mask[u] != mask[v]) {
			mst[edge++] = min++;
			small = mask[u] < mask[v]? mask[u]:mask[v];
			large = mask[u] < mask[v]? mask[v]:mask[u];
			for(int i = 0; i < n-1; i++) {
				if(mask[i] == large) {
					mask[i] = small;
				}
			}
		}
		else{
			cycle++;
		}
	}
	t2 = clock();
	t3 = t2 - t1;

	if(edge < n-1) {
		Memo1->Lines->Add("No MSTree in This Graph!");
	}
	else {
		if(CheckBox2->Checked) {
			for(int i = 0; i < n-1; i++) {
				Form1->Memo1->Lines->Add("Edge " + IntToStr(i) + " : (" + IntToStr(Edge2[mst[i]][0]) + "," + IntToStr(Edge2[mst[i]][1]) + ") [" + IntToStr(Edge2[mst[i]][2]) + "]");
			}
		}
		Memo1->Lines->Add("# Edges incurring cycles : " + IntToStr(cycle));
		for(int i = 0; i < n-1; i++) {
			sum += Edge2[mst[i]][2];
		}
	}
	Memo1->Lines->Add("Kruskal : (" + IntToStr(n) + "," + IntToStr(sum) + "," + t3 + "(sec.))");
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				Form1->StringGrid2->Cells[j][i] = Edge2[i][j];
			}
		}

		for(int i = 0;i < v;i++) {
			delete[] Edge2[i];
		}
	delete[] Edge2;
	delete[] mst;
	delete[] mask;
	delete[] use;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	int min = 0,x = rand()%n,xx,sum = 0;
	int *X = new int [n];
	int *Y = new int [n];
	int *C1 = new int [n];
	int *C2 = new int [n];
	t1 = clock();
	for(int i = 0; i < n; i++) {
		C1[i] = x;
		C2[i] = Max_num;
		X[i] = 0;
		Y[i] = 1;
	}
	xx = 1;
	X[x] = 1;
	Y[x] = 0;
	while(xx < n) {
		for(int i = 0; i < n; i++) {
			if(Y[i] && (Edge[x][i] < C2[i] )) {
				C1[i] = x;
				C2[i] = Edge[x][i];
			}
		}
		min = 0;
		for(int i = 0; i < n; i++){
			if(C2[i] < C2[min]){
				min = i;
			}
		}
		if(C2[min] == Max_num) {
			break;
		}
		sum += C2[min];
		C2[min] = Max_num;
		X[min] = 1;
		Y[min] = 0;
		x = min;
		xx++;
	}
	t2 = clock();
	t3 = t2 - t1;

	if(xx < n-1) {
		Memo1->Lines->Add("No MSTree in This Graph!");
		sum = 0;
	}
	else {
		if(CheckBox2->Checked){
			for(int i = 0; i < n; i++){
				Form1->Memo1->Lines->Add("Edge " + IntToStr(i) + " : (" + IntToStr(i) + "," + IntToStr(C1[i]) + ") [" + IntToStr(Edge[i][C1[i]]) + "]");
			}
		}
	}
	Memo1->Lines->Add("Prim : (" + IntToStr(n) + "," + IntToStr(sum) + "," + t3 + "(sec.))");

	delete[] X;
	delete[] Y;
	delete[] C1;
	delete[] C2;
}
//---------------------------------------------------------------------------
