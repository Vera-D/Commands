#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int counter = 0;
    int x;
	int row = 0;
	int column = 0;
	string temp, temp2;
    ifstream inFile;
    stringstream ss;
	string header = ">";
	string fastaHeader = "";
    inFile.open("full_20m.tsv");
	ofstream outFile("output20M.txt");
	inFile.tie(&outFile);

    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
	//loop through the line
    while (inFile) {
		//counter = counter+ counter;
		header="";
		row++;
		getline (inFile,temp);
		istringstream ss( temp );
		//temp = ">lineA:"+to_string(row)+":"+temp;
		//cout << row << endl;
		
		column =0;
		
		while(ss){
			
			getline (ss,temp2,'\t');
			
			if(column < 3){
				header =  temp2+":"+header;
				column++;
				
			}
			else{
				column++;
				if(temp2=="NNNNNN" ||temp2=="" ){
				
				}else{
					fastaHeader = ">Row"+header + to_string(counter)+":";
					cout << fastaHeader << endl;
					cout << temp2 << endl;
					
					outFile << fastaHeader << endl;
					outFile << temp2 << endl;
					counter++;
					
				}
			}
		}
		//counter = 0;

	}
    
    inFile.close();

    return 0;
}