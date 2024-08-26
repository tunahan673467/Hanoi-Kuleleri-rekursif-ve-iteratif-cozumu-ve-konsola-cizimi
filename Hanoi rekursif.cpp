#include<iostream>
using namespace std;
void Hanoi(int n, char kaynak, char ara, char hedef) {
if (n == 1) {
 cout << n << ".Diski " << kaynak << " dan " << hedef << " ye tasi." << endl;
return;
 }
else {
 Hanoi(n - 1, kaynak, hedef, ara);
 cout << n << ".Diski " << kaynak << " dan " << hedef << " ye tasi." << endl;
 Hanoi(n - 1, ara, kaynak, hedef);
 }
} int main() { int
diskSayisi; cout <<
"Disk Sayisi:";
cin>>diskSayisi;
 Hanoi(diskSayisi, 'A', 'B', 'C');
return 0;
}
