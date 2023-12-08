#include "list.h"

double skaiciuoti_galutini(const list<int>& nd, int egz) {
    double suma = 0;
    for (int pazymys : nd) {
        suma += pazymys;
    }
    double vidurkis = suma / nd.size();
    return 0.4 * vidurkis + 0.6 * egz;
}

list<StudentasL> nuskaityti_duomenis_list(const string& failo_vardas) {
    list<StudentasL> studentai; 
    ifstream failas(failo_vardas); 
    if (failas.fail()) { 
        throw runtime_error("Nepavyko atidaryti failo " + failo_vardas); 
    }
    string eilute;
    getline(failas, eilute); 
    while (getline(failas, eilute)) { 
        StudentasL s; 
        stringstream ss(eilute); 
        ss >> s.vardas >> s.pavarde; 
        int pazymys;
        while (ss >> pazymys) { 
            s.nd.push_back(pazymys);
        }
        s.egz = s.nd.back(); 
        s.nd.pop_back(); 
        s.galutinis = skaiciuoti_galutini(s.nd, s.egz); 
        studentai.push_back(s); 
    }
    failas.close(); 
    return studentai; 
}
void isvesti_duomenis_list(const string& failo_vardas, const list<StudentasL>& studentai) {
    ofstream failas(failo_vardas); 
    if (failas.fail()) { 
        throw runtime_error("Nepavyko atidaryti failo " + failo_vardas);
    }
    failas << "Vardas\tPavarde\tGalutinis\n";
    for (const StudentasL& s : studentai) { 
        failas << s.vardas << "\t" << s.pavarde << "\t" << s.galutinis << "\n"; 
    }
    failas.close();
}
pair<list<StudentasL>, list<StudentasL>> padalinti_studentus_list(const list<StudentasL>& studentai) {
    list<StudentasL> vargsiukai_list; 
    list<StudentasL> kietiakiai_list; 
    for (const StudentasL& s : studentai) { 
        if (s.galutinis < 5.0) { 
            vargsiukai_list.push_back(s); 
        } else { 
            kietiakiai_list.push_back(s); 
        }
    }
    return make_pair(vargsiukai_list, kietiakiai_list); 
}

list<StudentasL> istrinti_vargsiukus_list(list<StudentasL>& studentai) {
    list<StudentasL> vargsiukai_list; 
    auto it = studentai.begin(); 
    while (it != studentai.end()) { 
        if (it->galutinis < 5.0) { 
            vargsiukai_list.push_back(*it); 
            it = studentai.erase(it); 
        } else { 
            it++; 
        }
    }
    return vargsiukai_list; 
}

void surusiuoti_studentus_list(list<StudentasL>& studentai) {
    studentai.sort([] (const StudentasL& a, const StudentasL& b) {
        if (a.vardas < b.vardas) return true;
        if (a.vardas > b.vardas) return false;
        if (a.pavarde < b.pavarde) return true;
        if (a.pavarde > b.pavarde) return false;
        return a.galutinis < b.galutinis;
    });
}
