#include <vector>
#include <list>
#include <utility>
#include <iostream>
#include "vector.h"
#include "list.h"
using namespace std;

 
int main() {
  try {
    auto start_read = high_resolution_clock::now();
    vector<Studentas> studentai = nuskaityti_duomenis_vector("studentai10000.txt");
    auto stop_read = high_resolution_clock::now();
    auto duration_read = duration_cast<microseconds>(stop_read - start_read);
    auto start_other = high_resolution_clock::now();
    pair<vector<Studentas>, vector<Studentas>> padalinimas = padalinti_studentus_vector(studentai);
    surusiuoti_studentus_vector(padalinimas.first);
    surusiuoti_studentus_vector(padalinimas.second);
    isvesti_duomenis_vector("vargsiukai_s1.txt", padalinimas.first);
    isvesti_duomenis_vector("kietiakai_s1.txt", padalinimas.second);
    auto stop_other= high_resolution_clock::now();
    auto duration_other = duration_cast<microseconds>(stop_other - start_other);

    vector<Studentas>Stud_s2;
    auto start_nuskaitymas = high_resolution_clock::now();  
    Stud_s2 = nuskaityti_duomenis_vector("studentai10000.txt");
    auto stop_nuskaitymas= high_resolution_clock::now();  
    auto duration_nuskaitymas = duration_cast<microseconds>(stop_nuskaitymas - start_nuskaitymas);
    auto start_kita= high_resolution_clock::now();
    vector<Studentas> vargsiukai_vector= istrinti_vargsiukus_vector(Stud_s2);
    isvesti_duomenis_vector("vargsiukai_s2.txt", vargsiukai_vector);
    isvesti_duomenis_vector("studentai_s2.txt", studentai);
    auto stop_kita= high_resolution_clock::now();
    auto duration_kita= duration_cast<microseconds>(stop_kita-start_kita);


    auto start_read_list = high_resolution_clock::now();
      list<StudentasL> studentaiL1= nuskaityti_duomenis_list("studentai10000.txt"); 
      auto stop_read_list = high_resolution_clock::now();
      auto duration_read_list = duration_cast<microseconds>(stop_read_list - start_read_list);
      auto start_kiti = high_resolution_clock::now();
      pair<list<StudentasL>, list<StudentasL>> padalinti = padalinti_studentus_list(studentaiL1);
      surusiuoti_studentus_list(padalinti.first); 
      surusiuoti_studentus_list(padalinti.second);
      isvesti_duomenis_list("vargsiukai_l_s1", padalinti.first);
      isvesti_duomenis_list("kietiakai_l_s1", padalinti.second);
      auto stop_kiti = high_resolution_clock::now();
      auto duration_kiti = duration_cast<microseconds>(stop_kiti - start_kiti);

     list <StudentasL> studentaiL;
     auto start_nuskaitymas_list = high_resolution_clock::now();
     studentaiL = nuskaityti_duomenis_list("studentai10000.txt"); 
     auto stop_nuskaitymas_list = high_resolution_clock::now();
     auto duration_nuskaitymas_list = duration_cast<microseconds>(stop_nuskaitymas_list - start_nuskaitymas_list);
     auto start_kiti_list = high_resolution_clock::now();
     list<StudentasL>vargsiukai_list= istrinti_vargsiukus_list(studentaiL);
     isvesti_duomenis_list("vargsiukai_l_st2", vargsiukai_list);
     auto stop_kiti_list = high_resolution_clock::now();
     auto duration_kiti_list = duration_cast<microseconds>(stop_kiti_list - start_kiti_list);

    cout << "Vector nuskaitymas su 1 strat: " << duration_read.count()/1000000.0 << " sek.\n";
     cout << "List nuskaitymas su 1 strat: " << duration_read_list.count()/1000000.0 << " sek.\n";
    cout<<"Skirtumas:"<< (duration_read_list.count()/1000000.0)-duration_read.count()/1000000.0<<"sek.\n";
    cout<<"--------------------------------------------";
      
    cout << "Vector kitos operacijos su 1 strat: " << duration_other.count()/1000000.0 << " sek.\n";
     cout << "List kitos operacijos su 1 strat: " << duration_kiti.count()/1000000.0 << " sek.\n";
    cout<<"Skirtumas:"<<(duration_kiti.count()/1000000.0)-(duration_other.count()/1000000.0)<<"sek.\n";
    cout<<"--------------------------------------------";
    
    cout << "Vector nuskaitymas su 2 strat: " << duration_nuskaitymas.count()/1000000.0 << " sek.\n";
     cout << "List nuskaitymas su 2 strat: " << duration_nuskaitymas_list.count()/1000000.0 << " sek.\n";
    cout<<"Skirtumas:"<<(duration_nuskaitymas_list.count()/1000000.0)-(duration_nuskaitymas.count()/1000000.0)<<"sek.\n";
      cout<<"------------------------------------------";
    
    cout << "Vector kitos operacijos su 2 strat: " << duration_kita.count()/1000000.0 << " sek.\n";
     cout << "List kitos operacijos su 2 strat: " << duration_kiti_list.count()/1000000.0 << " sek.\n";
    cout<<"Skirtumas:"<<(duration_kiti_list.count()/1000000.0)-(duration_kita.count()/1000000.0)<<"sek.\n";
    cout<<"------------------------------------------";

    cout<<"Vector 1strat vs 2strat: "<<((duration_read.count()/1000000.0)+duration_other.count()/1000000.0)-((duration_nuskaitymas.count()/1000000.0 )+(duration_kita.count()/1000000.0))<<"sek.\n";
    cout<<"List 1strat vs 2 strat: "<<((duration_read_list.count()/1000000.0)+(duration_kiti.count()/1000000.0))-((duration_nuskaitymas_list.count()/1000000.0)+(duration_kiti_list.count()/1000000.0))<<"sek.\n";
  }
    catch (const exception& e){
            cout << "Klaida: " << e.what() << "\n";
        }return 0;
}
