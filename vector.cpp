#include "vector.h"


double skaiciuoti_galutini(const vector<int>& nd, int egz) {
    double suma = 0;
    for (int pazymys : nd) {
        suma += pazymys;
    }
    double vidurkis = suma / nd.size();
    return 0.4 * vidurkis + 0.6 * egz;
}

vector<Studentas> nuskaityti_duomenis_vector(const string& failo_vardas) {
    vector<Studentas> studentai;
    ifstream failas(failo_vardas); 
    if (failas.fail()) { 
        throw runtime_error("Nepavyko atidaryti failo " + failo_vardas);
    }
    string eilute; 
    getline(failas, eilute); 
    while (getline(failas, eilute)) { 
        Studentas s; 
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

void isvesti_duomenis_vector(const string& failo_vardas, const vector<Studentas>& studentai) {
    ofstream failas(failo_vardas); 
    if (failas.fail()) { 
        throw runtime_error("Nepavyko atidaryti failo " + failo_vardas);
    }
    failas << "Vardas\tPavarde\tGalutinis\n"; 
    for (const Studentas& s : studentai) { 
        failas << s.vardas << "\t" << s.pavarde << "\t" << s.galutinis << "\n"; 
    }
    failas.close(); 
}

pair<vector<Studentas>, vector<Studentas>> padalinti_studentus_vector(const vector<Studentas>& studentai) {
    vector<Studentas> vargsiukai_vector;
    vector<Studentas> kietiakiai_vector; 
    for (const Studentas& s : studentai) { 
        if (s.galutinis < 5.0) { 
            vargsiukai_vector.push_back(s); 
        } else { 
            kietiakiai_vector.push_back(s); 
        }
    }
    return make_pair(vargsiukai_vector, kietiakiai_vector); 
}

vector <Studentas> istrinti_vargsiukus_vector(vector<Studentas> studentai) {
    vector<Studentas> vargsiukai_vector; 
    auto it = remove_if(studentai.begin(), studentai.end(), [&vargsiukai_vector] (const Studentas& s) {
        if (s.galutinis < 5.0) { 
            vargsiukai_vector.push_back(s); 
            return true; 
        } else { 
            return false; 
        }
    });
    studentai.erase(it, studentai.end()); 
    return vargsiukai_vector; 
}

void surusiuoti_studentus_vector(vector<Studentas>& studentai) {
    sort(studentai.begin(), studentai.end(),[] (const Studentas& a, const Studentas& b) {
        if (a.vardas < b.vardas) return true;
        if (a.vardas > b.vardas) return false;
        if (a.pavarde < b.pavarde) return true;
        if (a.pavarde > b.pavarde) return false;
        return a.galutinis > b.galutinis;
    });
}
