#include <iostream>
#include <fstream>
#include <string>
#include<cstdlib>
#include <ctime>
using namespace std;

inline char** LoadedGrid(int totrows,int totcols, string Gridfile){

	char** Grid = new char*[totrows];
	for(int i=0;i<totrows;i++)
		Grid[i] = new char[totcols];

	ifstream IN(Gridfile.c_str());
	for(int i=0;i<totrows;i++)
        for(int j=0;j<totcols;j++)
            Grid[i][j] = ' ';

    for(int i=0;i<totrows;i++)
        for(int j=0;j<totcols;j++)
            IN >> Grid[i][j];
	IN.close();
	return Grid;
}

int LeftToRight(char** Grid, char* word,int totrows,int totcols, ofstream& fout){

	int startrow = 0;
	int startcol = 0;
	int j=0;
	int endrow = 0;
	int endcol = 0;
	int length_count =0;
	int check = 1;

	

	for(int f=0;word[f]!='\0';f++)
		length_count++;


	for(int i = 0;i<totrows;i++){
		for(j=0;j<totcols;j++){
			if(Grid[i][j]==word[0]){
				startrow = i;
				startcol = j;
				endrow = startrow;
				j++;
				{
					int k=1;
					while(word[k]!='\0'){
						if(Grid[i][j]==word[k]){
							k++;
							j++;
							check++;
						}
						else{
							j=j-check;
							break;
						}
					}
				}
				endcol = j-1;
			}
					
			if(check == length_count)
				break;
			else{
				check =1;
				startrow = 0;
				startcol = 0;
				endrow = 0;
				endcol = 0;
			}
		}
		if(check!=1)
			break;
		check = 1;
	}
	
	if(startrow!=0 || startcol!=0 || endrow!=0 || endcol!=0){
		fout<<"{"<<startrow<<",";
		fout<<startcol<<"} ";
		fout<<"{"<<endrow<<",";
		fout<<endcol<<"}";
		fout<<endl;
		return 0;
	}
	else
		return -1;	

}

int RightToLeft(char** Grid, char* word,int totrows,int totcols, ofstream& fout){
	
	int startrow = 0;
	int startcol = 0;
	int endrow = 0;
	int endcol = 0;
	int length_count =0;
	int check = 1;


	for(int f=0;word[f]!='\0';f++)
		length_count++;	
		
	for(int i = 0;i<totrows;i++){
		for(int j=totcols;j>0;j--){
			if(Grid[i][j]==word[0]){
				startrow = i;
				startcol = j;
				endrow = startrow;
				j--;
				{
					int k=1;
					while(word[k]!='\0'){
						if(Grid[i][j]==word[k]){
							k++;
							j--;
							check++;
						}
						else{
							j=j+check;
							break;
						}
					}
				}
				endcol = j+1;
			}
					
			if(check == length_count)
				break;
			else{
				check =1;
				startrow = 0;
				startcol = 0;
				endrow = 0;
				endcol = 0;
			}
		}
		if(check!=1)
			break;
		check = 1;
	}

//	ofstream fout("Output.txt"); 
	if(startrow!=0 || startcol!=0 || endrow!=0 || endcol!=0){
		fout<<"{"<<startrow<<",";
		fout<<startcol<<"} ";
		fout<<"{"<<endrow<<",";
		fout<<endcol<<"}";
		fout<<endl;
		return 0;
	}
	else
		return -1;	

}

int TopToBottom(char** Grid, char *word,int totrows,int totcols, ofstream& fout){
	
	int startrow = 0;
	int startcol = 0;
	int endrow = 0;
	int endcol = 0;
	int j=0;
	int length_count =0;
	int m=0;
	int check = 1;

	

	for(int f=0;word[f]!='\0';f++)
		length_count++;

	for(j=0;j<totrows;j++){
		for(int i = 0;i<totcols;i++){
			if(Grid[j][i]==word[0]){
				startcol = i;
				startrow = j;
				endcol = startcol;
				j++;
				{
					int k=1;
					while(word[k]!='\0'){
						if(Grid[j][i]==word[k]){
							k++;
							j++;
							check++;
						}
						else{
							j=j-check;
							break;
						}
					}
				}
				endrow = j-1;
			}
					
			if(check == length_count)
				break;
			else{
				check =1;
				startrow = 0;
				startcol = 0;
				endrow = 0;
				endcol = 0;
			}
		}
		if(check!=1)
			break;
		check =1;
	}
	
//	ofstream fout("Output.txt"); 
	if(startrow!=0 || startcol!=0 || endrow!=0 || endcol!=0){
		fout<<"{"<<startrow<<",";
		fout<<startcol<<"} ";
		fout<<"{"<<endrow<<",";
		fout<<endcol<<"}";
		fout<<endl;
		return 0;
	}
	else
		return -1;		

}

int BottomToTop(char** Grid, char *word,int totrows,int totcols, ofstream& fout){
	
	int startrow = 0;
	int startcol = 0;
	int endrow = 0;
	int endcol = 0;
	int length_count =0;
	int check = 1;

	

	for(int f=0;word[f]!='\0';f++)
		length_count++;

		
	for(int j=totrows-1;j>0;j--){
		for(int i =0;i<totcols;i++){
			
			if(Grid[j][i]==word[0]){
					startcol = i;
					startrow = j;
					endcol = startcol;
					j--;
					{
						int k=1;
						while(word[k]!='\0'){
							if(Grid[j][i]==word[k]){
								k++;
								j--;
								check++;
							}
							else{
								j=j+check;
								break;
							}
						}
					}
					endrow = j + 1;
				}
					
				if(check == length_count){
					break;
				}
				else{
					check =1;
					startrow = 0;
					startcol = 0;
					endrow = 0;
					endcol = 0;
				}
			}
			if(check!=1)
				break;
			check = 1;
		}

//	ofstream fout("Output.txt"); 
	if(startrow!=0 || startcol!=0 || endrow!=0 || endcol!=0){
		fout<<"{"<<startrow<<",";
		fout<<startcol<<"} ";
		fout<<"{"<<endrow<<",";
		fout<<endcol<<"}";
		fout<<endl;
		return 0;
	}
	else
		return -1;	
}

int TopLeftToBottomRight(char** Grid, char *word,int totrows,int totcols, ofstream& fout){
	int startrow = 0;
	int startcol = 0;
	int endrow = 0;
	int endcol = 0;
	int j=0;
	int length_count =0;
	int check = 1;

	

	for(int f=0;word[f]!='\0';f++)
		length_count++;

	for(j=0;j<totrows;j++){
		for(int i = 0;i<totcols;i++){
			if(Grid[j][i]==word[0]){
				startcol = i;
				startrow = j;
				i++;
				j++;
				{
					int k=1;
					while(word[k]!='\0'){
						if(Grid[j][i]==word[k]){
							k++;
							j++;
							i++;
							check++;
						}
						else{
							j=j-check;
							i=i-check;
							break;
						}
					}
				}
				endrow = j-1;
				endcol = i-1;
			}
					
			if(check == length_count)
				break;
			else{
				check =1;
				startrow = 0;
				startcol = 0;
				endrow = 0;
				endcol = 0;
			}
		}
		if(check!=1)
			break;
		check = 1;
	}
//	ofstream fout("Output.txt"); 
	if(startrow!=0 || startcol!=0 || endrow!=0 || endcol!=0){
		fout<<"{"<<startrow<<",";
		fout<<startcol<<"} ";
		fout<<"{"<<endrow<<",";
		fout<<endcol<<"}";
		fout<<endl;
		return 0;
	}
	else
		return -1;		

}

int TopRightToBottomLeft(char** Grid, char *word,int totrows,int totcols,ofstream& fout){
	int startrow = 0;
	int startcol = 0;
	int endrow = 0;
	int endcol = 0;
	int j=0;
	int length_count =0;
	int check = 1;
	

	for(int f=0;word[f]!='\0';f++)
		length_count++;
	
	for(j=0;j<totrows;j++){
		for(int i =0;i<totcols;i++){
			if(Grid[j][i]==word[0]){
				startcol = i;
				startrow = j;
				i--;
				j++;
				{
					int k=1;
					while(word[k]!='\0'){
						if(Grid[j][i]==word[k]){
							k++;
							j++;
							i--;
							check++;
						}
						else{
							j=j-check;
							i=i+check;
							break;
						}
					}
				}
				endrow = j-1;
				endcol = i+1;
			}
					
			if(check == length_count)
				break;
			else{
				check =1;
				startrow = 0;
				startcol = 0;
				endrow = 0;
				endcol = 0;
			}
		}
		if(check!=1)
			break;
		check = 1;
	}

//	ofstream fout("Output.txt"); 
	if(startrow!=0 || startcol!=0 || endrow!=0 || endcol!=0){
		fout<<"{"<<startrow<<",";
		fout<<startcol<<"} ";
		fout<<"{"<<endrow<<",";
		fout<<endcol<<"}";
		fout<<endl;
		return 0;
	}
	else
		return -1;	
	
}

int BottomLeftToTopRight(char** Grid, char *word,int totrows,int totcols, ofstream& fout){
	int startrow = 0;
	int startcol = 0;
	int endrow = 0;
	int endcol = 0;
	int check = 1;
	int j=0;
	int length_count =0;

	

	for(int f=0;word[f]!='\0';f++)
		length_count++;

	for(j=totrows-1;j>0;j--){
		for(int i =totcols-1;i>0;i--){
			if(Grid[j][i]==word[0]){
				startcol = i;
				startrow = j;
				i++;
				j--;
				{
					int k=1;
					while(word[k]!='\0'){
						if(Grid[j][i]==word[k]){
							k++;
							j--;
							i++;
							check++;
						}
						else{
							j=j+check;
							i=i-check;
							break;
						}
					}
				}
				endrow = j+1;
				endcol = i-1;
			}
					
			if(check == length_count)
				break;
			else{
				check =1;
				startrow = 0;
				startcol = 0;
				endrow = 0;
				endcol = 0;
			}
		}
		if(check!=1)
			break;
		check = 1;
	}
	//ofstream fout("Output.txt");
	if(startrow!=0 || startcol!=0 || endrow!=0 || endcol!=0){
		fout<<"{"<<startrow<<",";
		fout<<startcol<<"} ";
		fout<<"{"<<endrow<<",";
		fout<<endcol<<"}";
		fout<<endl;
		return 0;
	}
	else
		return -1;	

}

int BottomRightToTopLeft(char** Grid, char *word,int totrows,int totcols, ofstream& fout){
	int startrow = 0;
	int startcol = 0;
	int endrow = 0;
	int endcol = 0;
	int j=0;
	int check = 1;
	int length_count =0;

	

	for(int f=0;word[f]!='\0';f++)
		length_count++;

	for(j=totrows-1;j>0;j--){
		for(int i =totcols-1;i>0;i--){
			if(Grid[j][i]==word[0]){
				startcol = i;
				startrow = j;
				i--;
				j--;
				{
					int k=1;
					while(word[k]!='\0'){
						if(Grid[j][i]==word[k]){
							k++;
							j--;
							i--;
							check++;
						}
						else{
							j=j+check;
							i=i+check;
							break;
						}
					}
				}
				endrow = j+1;
				endcol = i+1;
			}
					
			if(check == length_count)
				break;
			else{
				check =1;
				startrow = 0;
				startcol = 0;
				endrow = 0;
				endcol = 0;
			}
		}
		if(check!=1)
			break;
		check = 1;
	}
//	ofstream fout("Output.txt");
	if(startrow!=0 || startcol!=0 || endrow!=0 || endcol!=0){
		fout<<"{"<<startrow<<",";
		fout<<startcol<<"} ";
		fout<<"{"<<endrow<<",";
		fout<<endcol<<"}";
		fout<<endl;
		return 0;
	}
	else
		return -1;	
}

void SearchUsersinGrid( string Grid, string Search, string output)
{
	int totrows = 0;
	int totcols = 0;
	ifstream CIN(Search.c_str());
	//INPUT DATA
	CIN>>totrows;
	CIN>>totcols;
	int totwords ;
	CIN>>totwords;
	char** word = new char*[totwords];
	for(int i=0;i<totwords;i++)
		word[i] = new char[80];
	CIN.ignore();
	for(int j=0;j<totwords;j++){
		CIN.getline(word[j],80);
	}
	char** GRID= LoadedGrid(totrows, totcols, Grid);

	ofstream fout(output.c_str());
	for(int j=0;j<totwords;j++){
		int	a = LeftToRight(GRID, word[j],totrows,totcols,fout);
		int b = RightToLeft(GRID, word[j],totrows,totcols,fout);
		int c = TopToBottom(GRID, word[j],totrows,totcols,fout);
		int d = BottomToTop(GRID, word[j],totrows,totcols,fout);
		int e = TopLeftToBottomRight(GRID, word[j],totrows,totcols,fout);
		int f = TopRightToBottomLeft(GRID, word[j],totrows,totcols,fout);
		int g = BottomLeftToTopRight(GRID, word[j],totrows,totcols,fout);
		int h = BottomRightToTopLeft(GRID, word[j],totrows,totcols,fout);
		if(a == -1 && b == -1 && c == -1 && d == -1 && e == -1 && f == -1 && g == -1 && h == -1){
			fout<<"NOT FOUND";
			fout<<endl;
		}
	}
}

static int StringLenght( char* str ){
	int length_count =0;
	for(int i=0;str[i]!='\0';i++){
		length_count++;
			if(str[i] == ' '){
				length_count = length_count - 1;
			}
	}
	return length_count;
}

inline char* GetStringFromBuffer(char* studentsList){
	char* Name = 0;
	int Name_Len = StringLenght(studentsList);
	if (Name_Len > 0){	
		Name = new char[Name_Len+1];
		char* tempDest = Name;
	
		for (char* tempSrc = studentsList; *tempSrc != '\0'; ){
			if(*tempSrc == ' '){
				tempSrc++;
				continue;
			}
			else{
				int x = int(*tempSrc);
				if(x > 96 && x < 123)
					*tempSrc = *tempSrc - 32;
				*tempDest = *tempSrc;
				tempSrc++;
				tempDest++;
			}
		}
	*tempDest = '\0';
	}
	return Name;

}

void SortingWords(char *word[20],int size, int& maxlength){
	char* temp;
	for(int i = 0;i<size ;i++){
		for(int j = i+1;j<size;j++){
		int wordsize1 = StringLenght(word[i]);
		int wordsize2 = StringLenght(word[j]);
			if(wordsize2 > wordsize1){
				maxlength=wordsize2;
				temp = word[i];
				word[i] = word[j];
				word[j] = temp;
			}
		}
	}
}

bool LeftToRight(char *Grid[10],char* word,int i,int j,int rows, int cols){
	bool yes = false;
	int length = StringLenght(word);
	int a = cols - j;
	if(length > a)
		return yes;
	if(j>=length)
		return yes;
	int indi =i;
	int indj =j;
	for(int m = 0;m<length;m++){
		int b = Grid[indi][indj];
		int c = word[m];
		if(c == b)
			continue;
		if(b >= 65 && b <= 90)
			return yes;
		indj++;
	}
	int indexi =i;
	int indexj =j;
	for(int l=0;l<length;l++){
		Grid[indexi][indexj]=word[l];
		indexj++;
	}
	return true;
}

bool RightToLeft(char *Grid[10],char* word,int i,int j,int rows, int cols){
	bool yes = false;
	int length = StringLenght(word);
	int a = cols - j;
	if(length > a)
		return yes;
	if(j>=length)
		return yes;
	int indi =i;
	int indj =j;
	for(int m = length - 1;m>=0;m--){
		int b = Grid[indi][indj];
		int c = word[m];
		if(c == b)
			continue;
		if(b >= 65 && b <= 90)
			return yes;
		indj++;
	}
	int indexi =i;
	int indexj =j;
	for(int l=length;l<0;l--){
		Grid[indexi][indexj]=word[l];
		indexj++;
	}
	return true;
}

bool TopToBottom(char *Grid[10],char* word,int i,int j,int rows, int cols){
	bool yes = false;
	int length = StringLenght(word);
	int a = rows - i;
	if(length > a)
		return yes;
	if(i>=length)
		return yes;
	int indi =i;
	int indj =j;
	for(int m = 0;m<length;m++){
		int b = Grid[indi][indj];
		int c = word[m];
		if(c == b)
			continue;
		if(b >= 65 && b <= 90)
			return yes;
		indi++;
	}
	int indexi =i;
	int indexj =j;
	for(int l=0;l<length;l++){
		Grid[indexi][indexj]=word[l];
		indexi++;
	}
	return true;
}

bool BottomToTop(char *Grid[10],char* word,int i,int j,int rows, int cols){
	bool yes = false;
	int length = StringLenght(word);
	int a = rows - i;
	if(length > a)
		return yes;
	if(i>=length)
		return yes;
	int indi =i;
	int indj =j;
	for(int m = length - 1;m>=0;m--){
		int b = Grid[indi][indj];
		int c = word[m];
		if(c == b)
			continue;
		if(b >= 65 && b <= 90)
			return yes;
		indi++;
	}
	int indexi =i;
	int indexj =j;
	for(int l=length;l<0;l--){
		Grid[indexi][indexj]=word[l];
		indexi++;
	}
	return true;
}

bool TopLeftToBottomRight(char *Grid[10],char* word,int i,int j,int rows, int cols){
	bool yes = false;
	int length = StringLenght(word);
	int a = rows - i;
	int d = cols - j;
	if(rows < a || cols < d)  
		return yes;
	if (i<length || j< length)
		return yes;
	if (i>=length || j>=length)
		return yes;
	int indi =i;
	int indj =j;
	for(int m = 0;m<length;m++){
		int b = Grid[indi][indj];
		int c = word[m];
		if(c == b)
			continue;
		if(b >= 65 && b <= 90)
			return yes;
		indj++;
		indi++;
	}
	int indexi =i;
	int indexj =j;
	for(int l=0;l<length;l++){
		Grid[indexi][indexj]=word[l];
		indexj++;
		indexi++;
	}
	return true;
}

bool TopRightToBottomLeft(char *Grid[10],char* word,int i,int j,int rows, int cols){
	bool yes = false;
	int length = StringLenght(word);
	int a = rows - i;
	int d = cols - j;
	
	if(i > rows || j < 0 )  
		return yes;
	if(a<length || d> length)
		return yes;
	if(i>=length || j<length-1)
		return yes;

	int indi =i;
	int indj =j;
	for(int m = 0;m<length;m++){
		int b = Grid[indi][indj];
		int c = word[m];
		if(c == b)
			continue;
		if(b >= 65 && b <= 90)
			return yes;
		indj--;
		indi++;
	}
	int indexi =i;
	int indexj =j;
	for(int l=0;l<length;l++){
		Grid[indexi][indexj]=word[l];
		indexj--;
		indexi++;
	}
	return true;
}

bool BottomRightToTopLeft(char *Grid[10],char* word,int i,int j,int rows, int cols){
	bool yes = false;
	int length = StringLenght(word);
	int a = i - length;
	int d = j - length;
	if(i<0 || j<0 )   
		return yes;
	if(i<length-1 || j< length-1)
		return yes;
	if (a>length || d>length)
		return yes;
	int indi =i;
	int indj =j;
	for(int m = 0;m<length;m++){
		int b = Grid[indi][indj];
		int c = word[m];
		if(c == b)
			continue;
		if(b >= 65 && b <= 90)
			return yes;
		indj--;
		indi--;
	}
	int indexi =i;
	int indexj =j;
	for(int l=0;l<length;l++){
		Grid[indexi][indexj]=word[l];
		indexj--;
		indexi--;
	}
	return true;
}

bool BottomLeftToTopRight(char *Grid[10],char* word,int i,int j,int rows, int cols){
	bool yes = false;
	int length = StringLenght(word);
	int a = i - length;
	int d = cols - j;
	if(i<0 || j>cols )  
		return yes;
	if (i<length-1 || j>= length)
		return yes;
	if(a>length || d<length)
		return yes;

	int indi =i;
	int indj =j;
	for(int m = 0;m<length;m++){
		int b = Grid[indi][indj];
		int c = word[m];
		if(c == b)
			continue;
		if(b >= 65 && b <= 90)
			return yes;
		indj++;
		indi--;
	}
	int indexi =i;
	int indexj =j;
	for(int l=0;l<length;l++){
		Grid[indexi][indexj] = word[l];
		indexj++;
		indexi--;
	}
	return true;
	
}

bool Randomizing(char *Grid[10], char* word, int r, int c, int random){ 

	if(random == 0){
		for(int i = 0; i<r;i++){
			for(int j = 0; j<c; j++){
				if(BottomLeftToTopRight(Grid, word, i, j, r,c))
					return true;
				else if(BottomToTop(Grid, word, i, j, r,c))
				
					return true;
			}
		}
	}
	if(random == 1){
		for(int i = 0; i<r;i++){
			for(int j = 0; j<c; j++){
				if(RightToLeft(Grid, word, i, j,  r,c))
					return true;
				else if(BottomLeftToTopRight(Grid, word, i, j,  r,c))
					return true;
			}
		}
	}
	if(random == 2){
		for(int i = 0; i<r;i++){
			for(int j = 0; j<c; j++){
				if(TopLeftToBottomRight(Grid, word, i, j,  r,c))
					return true;
				else if(TopRightToBottomLeft(Grid, word, i, j,  r,c))
					return true;
			}
		}
	}
	if(random == 3){
		for(int i = 0; i<r;i++){
			for(int j = 0; j<c; j++){
				if(LeftToRight(Grid, word, i, j,  r,c))
					return true;
				else if(TopToBottom(Grid, word, i, j, r,c))
				
					return true;
			}
		}	
	}
	if(random== 4){
		for(int i = 0; i<r;i++){
			for(int j = 0; j<c; j++){
				if(BottomRightToTopLeft(Grid, word, i, j, r,c))
					return true;
				else if(BottomToTop(Grid, word, i, j, r,c))
				
					return true;
			}
		}	
	}
	if(random == 5){
		for(int i = 0; i<r;i++){
			for(int j = 0; j<c; j++){
				if(TopRightToBottomLeft(Grid, word, i, j, r,c))
					return true;
				else if(LeftToRight(Grid, word, i, j, r,c))
					return true;
			}
		}	
	}
	return false;
}


int CreateGrid(string Input, string Output, int size, int Rows, int Cols)
{
	char** word;
	ifstream fin("Input.txt");
	int gridsize = 0;
	int wordsize = 0;
	char words[100];

	word=new char*[size];
	for(int i = 0;i<size;i++)
		word[i] = new char[40];


	int i = 0;
	ifstream myfile(Input.c_str());
	char temp[20];
	if(myfile.is_open()){
		for(;i<size;i++){
			myfile.getline(temp,20);
			word[i] = GetStringFromBuffer(temp);
		}
	}
	word[i]='\0';
	int maxlength=0;
	SortingWords(word,size, maxlength);

	if(maxlength>Rows ||maxlength>Cols)
		return 1;
	
	char** Grid = new char*[Rows];
	for(int i=0 ;i<Rows;i++)
		Grid[i] = new char[Cols];
	for(int i = 0; i<Rows;i++){
		for(int j =0;j<Cols;j++){
			Grid[i][j] = ' ';
		}
	}

	srand((unsigned)time(0));
	int random; 

	for(int f = 0; f < size; ){
		random = rand() % 8;
		if(Randomizing(Grid, word[f], Rows, Cols,random))
			f++;
		else
			random = rand() % 6;
	}
	

	char alphabets = 'A';
	for(int i = 0; i <Rows; i++){
		for(int j = 0; j <Cols; j++){
			int a = int(Grid[i][j]);
			if(a<65 ||a>90 ){
				Grid[i][j] = alphabets;
				alphabets++;
				if(i % 2 == 0)
					alphabets = alphabets + 6;
				if(j % 2 == 0)
					alphabets =alphabets + 4;
				int c = int(alphabets);
				if(c > 90)
					alphabets = alphabets - 26;
			}
		}
	}
	ofstream fout(Output.c_str());
	for(int i = 0; i<Rows;i++){
		for(int j =0;j<Cols;j++){
			fout<<Grid[i][j];
		}
		fout<<endl;	
	}
	return 0;
}

void main()
{
	char Choice='a';
	char A;
	int Noofwords, Rows, Cols;
	string  Input, Output, Search, Grid, output;

	while(Choice!='Q')
	{
		cout<<"1) Create Grid\n";
		cout<<"2) Search Words from Grid\n";
		cout<<"3) Quit\n";
		cout<<"Enter your choice:\t";

		cin>>Choice;	
		cout<<endl;

		if(Choice=='C')
		{
			cout<<"1) Name of the input file:\t";
			cin>>Input; 
			cout<<endl;
			cout<<"2) Number of words in the file:\t";
			cin>>Noofwords;
			cout<<endl;
			cout<<"3) Number of rows in the grid:\t";
			cin>>Rows;    
			cout<<endl;
			cout<<"4) Number of columns in the grid:\t";
			cin>>Cols;    
			cout<<endl;
			cout<<"5) Name of the output file where the grid needs to be placed:\t";
			cin>>Output;    
			cout<<endl;
			if( CreateGrid(Input, Output, Noofwords, Rows, Cols)==1)
				cout<<"'Grid cannot be formed, press any key to return to the home screen'\n";
	        cout<<"Press Any Key to return to the main menu\t";
			cin>>A;

		}
		if(Choice=='S')
		{
			cout<<"1) Name of the input file which has a grid in it:\t";
			cin>>Grid;
			cout<<endl;
			cout<<"2) Name of the file with input to be searched:\t";
			cin>>Search;
			cout<<endl;
			cout<<"3) Name of the output file:\t";
			cin>>output;    
			cout<<endl;
		 
			SearchUsersinGrid(Grid,Search,output);
			cout<<"Press Any Key to return to the main menu\t";
			cin>>A;
	
		}
		
	}
	

	if(Choice=='Q')
	{
		system("pause");
		return;
	}


	system("pause");
}