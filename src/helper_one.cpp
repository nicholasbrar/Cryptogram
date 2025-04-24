#include <iostream>
#include <map>

using namespace std;

int main() {
  string crypto = "QLIPX YLXDY ITQMM JINGE KGSOK RQCVS NIEKF QCWXH SFPSX KPQFK LPGIR SXENX XINXD EYJJL UQFKT JNFJM EISCC SDQCS PMEWR EGIYP QLXHN STPVQ DPXOI GDQNW YSILK KNXDF LJGLM WYGRL ZNPWA EYQNL WPQIY PVGXP CIXHA DUCEH IMEKJ FQMRG XYQQH PQCKK BMEWX VDIQO IMSOG DRTIN DPOMF SAMKO WMPPN TRJVC ITEYX MAMVC ERQML LXCIM XOAFF EAYKS KKBWC WREGG RLIFP WDDAJ VTKEA LTQCI YPVIR KULEK FPPAD D";

  string cleaned;
  for (char ch : crypto) {
      if (ch != ' ') {
          cleaned += ch;
      }
  }

  crypto = cleaned; 

  string first = "";
  string second = "";
  string third = "";
  string fourth = "";

  for(int i = 0; i < crypto.length(); i+=4){
    if (isalpha(crypto[i])) {  
        char base = islower(crypto[i]) ? 'a' : 'A';  
        crypto[i] = (crypto[i] - base + 18) % 26 + base;  
    }
    if (isalpha(crypto[i+2])) {  
        char base = islower(crypto[i+2]) ? 'a' : 'A';  
        crypto[i+2] = (crypto[i+2] - base + 5) % 26 + base;  
    }
    if (isalpha(crypto[i+3])) {  
        char base = islower(crypto[i+3]) ? 'a' : 'A';  
        crypto[i+3] = (crypto[i+3] - base + 4) % 26 + base;  
    }
  }

  string cleaned_again;
  for (char ch : crypto) {
      if (ch != ' ') {
          cleaned_again += ch;
      }
  }

  crypto = cleaned_again; 


  cout << crypto << endl;

  return 0;
}
