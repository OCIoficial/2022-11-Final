#include "testlib.h"

using namespace std;

int main(){
	registerValidation();
	int n = inf.readInt(2, 2, "n");
	inf.readSpace();
	int m = inf.readInt(1, 1e3, "m");
    inf.readSpace();
	int k = inf.readInt(2, 2, "k");
	inf.readEoln();
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (j) inf.readSpace();
            inf.readInt(1,k,"color [" + to_string(i) + " , " + to_string(j) + "]" );
        }
        inf.readEoln();
    }
	inf.readEof();
}