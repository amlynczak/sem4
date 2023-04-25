/*
Zadanie udostępniam dość późno, ale jest bardzo proste, polega głównie na zgłębieniu tematu i zbudowaniu w pewien sposób zależnych od siebie klas (maks godzinka roboty). Na poniedziałkowych zajęciach będziemy je rozbudowywać.
Nie czekałam na instrukcje koordynatora, pełną wirtualizację zrobimy sobie za tydzień.
---------------
Należy zaimplementować następujące klasy:
* RNA - implementuje dowolną sekwencję nukleotydów - łańcuch RNA.
  Nukleotydy są nowym typem enum:
	A='A', // adeine 
	G='G', // guanine
	C='C', // citozine
	T='T', // thymine
	U='U'  // uracil
UWAGA - Można mutować łańcuch.
* Virus (virus.h) - klasa implemetuje wirus o następujących cechach:
  - nazwa
  - łańcuch RNA (dynamiczny obiekt RNA)
  - "wiek" wirusa - ilość wyprodukowanych pokoleń
    Wiek wirusa zwiększa się o jeden, po każdej replikacji (skopiowaniu konstr. kopiującym).
    Na przykład, jeśli wiek wirusa vir1 wynosi 1, to nowy wirus vir2 utworzony przez instrukcję 'Virus vir2(vir1)' bedzie miał wiek 0, zaś vir1 wiek 2.
*/

#include <iostream>

#include "rna.h"
#include "dna.h"
#include "virus.h"

using namespace std;

//----------------------------------------------------
int main() {
	// tworzymy dwie sekwencje genów
	RNA rna1( vector<Nukleotyp>({A,C,A,T,A,G,A,C,T,A,G,T,C,A,T}) );
	RNA rna2( vector<Nukleotyp>({C,A,T,C,C,A,G,A,G,T,A,C,T,C,A}) );
	cout << "RNA1: " << rna1 << "RNA2: " <<rna2;
	// mutujemy RNA - przesuwamy rotacyjnie w lewo
	cout << "MUTATED RNA2: " << rna2.mutate();
	
	// tworzymy kod DNA
	DNA kodDNA(rna1,rna2);
	cout << kodDNA << endl;
	
	// tworzymy nowego wirusa (z pustą informacją o kodzie RNA)
	Virus vir1("RSV");
	cout << "Wirus: " << vir1.get_name() << " " << vir1.get_RNA() << endl;
	// dodajemy sekwencję RNA
	vir1.set_RNA(vector<Nukleotyp>({A,C,U,A,G,G,U,A,U,G,A}));	
	cout << "RNA: " << *vir1.get_RNA() << endl;

	Virus vir2 = Virus(vir1);
	Virus vir3(vir1); 
	Virus vir4(vir3);
	cout << "Pokolenia: " << endl;
	cout << "Vir1 - Wiek: " << vir1.get_age() << "  RNA: " << *vir1.get_RNA();
	cout << "Vir2 - Wiek: " << vir2.get_age() << "  RNA: " << *vir2.get_RNA();
	cout << "Vir3 - Wiek: " << vir3.get_age() << "  RNA: " << *vir3.get_RNA();

	return 0;
}
// =======================================================================

/* *** Oczekiwane wyjście
RNA1: A C A T A G A C T A G T C A T
RNA2: C A T C C A G A G T A C T C A
MUTATED RNA2: A T C C A G A G T A C T C A C
A C A T A G A C T A G T C A T
| | | | | | | | | | | | | | |
A T C C A G A G T A C T C A C

Wirus: RSV 0
RNA: A C U A G G U A U G A

Pokolenia:
Vir1 - Wiek: 2  RNA: A C U A G G U A U G A
Vir2 - Wiek: 0  RNA: A C U A G G U A U G A
Vir3 - Wiek: 1  RNA: A C U A G G U A U G A

*/
