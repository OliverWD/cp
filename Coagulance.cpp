#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const char ABOBloodType[6][3] = {"A", "AB", "A", "B", "B", "O"};
const char AlleleCombinations[6][3] = {"AA", "AB", "AO", "BB", "BO", "OO"};
const char allCombs[8][4] = {"O-", "O+", "B-", "B+", "AB-", "AB+", "A-", "A+"};


void generateCombos(const vector<string> &A1, const vector<string> &A2, vector<string> &combos) {
    for (const auto &i : A1) {
        for (const auto &j : A2) {
            for (int a = 0; a < 2; a++) {
                for (int b = 0; b < 2; b++) {
                    /* New combo */
                    string allele;
                    allele += i[a];
                    allele += j[b];
                    /* Ensure pushing only unique values onto combos */
                    sort(allele.begin(), allele.end());
                    if (find(combos.begin(), combos.end(), allele) == combos.end()) {
                        combos.push_back(allele);
                    }
                }
            }
        }
    }
}

void getBloodType(const string & alleles, string & type) {
    if (alleles == "AA" || alleles == "AO")
        type = "A";
    if (alleles == "AB")
        type = "AB";
    if (alleles == "BB" || alleles == "BO")
        type = "B";
    if (alleles == "OO")
        type = "O";
}

void generateAlleleRhCombo (string A1, string A2, vector <string> & alleleCombo,
                            vector <string> & rhCombo)
{
    char rh1 = A1.back(); A1.pop_back();
    char rh2 = A2.back(); A2.pop_back();
    vector<string> A1pos, A2pos;

    for (int i = 0; i < 6; i++) {
        string tmp = AlleleCombinations[i];
        if (A1 == ABOBloodType[i])
            A1pos.push_back(tmp);
        if (A2 == ABOBloodType[i])
            A2pos.push_back(tmp);
    }

    // first generate rh combos
    vector <string> rh1Pos;
    if (rh1 == '+') {
        rh1Pos.emplace_back("++");
        rh1Pos.emplace_back("+-");
    } else
        rh1Pos.emplace_back("--");

    vector <string> rh2Pos;
    if (rh2 == '+') {
        rh2Pos.emplace_back("++");
        rh2Pos.emplace_back("+-");
    } else
        rh2Pos.emplace_back("--");

    generateCombos(rh1Pos, rh2Pos, rhCombo);
    generateCombos(A1pos, A2pos, alleleCombo);
}


bool non_child (const string & dad, const string & mum, string child) {

    char rhChild = child.back(); child.pop_back();

    vector <string> alleleCombos, rhCombos;
    generateAlleleRhCombo(dad, mum, alleleCombos, rhCombos);

    for (const auto &alleleCombo : alleleCombos) {
        for (const auto &rhCombo : rhCombos) {

            string bloodType;
            getBloodType(alleleCombo, bloodType);

            if (bloodType != child)
                continue;

            if (rhChild == '-')
                if (rhCombo == "--")
                    return true;
            if (rhChild == '+')
                if (rhCombo != "--")
                    return true;
        }
    }
    return false;
}

void clean (vector <string> & out) {
    /* Erase duplicates and sort */
    sort(out.begin(), out.end());
    auto last = unique(out.begin(), out.end());
    out.erase(last, out.end());
}

void print_nice(const vector <string> & out) {

    if (out.empty()) {
        cout << "IMPOSSIBLE";
    }
    else if (out.size() == 1) {
        cout << out[0];
    }
    else {
        cout << "{";
        int i = (int) out.size() - 1;
        for (; i > 0; i--) {
            cout << out[i] << ", ";
        }
        cout << out[i] << "}";
    }
}

int main () {

    /* CLion doesn't handle standard input yet..? */
    // freopen("/home/olliee/CLionProjects/c11/out.txt", "a+", stdout);
    // freopen("/home/olliee/CLionProjects/c11/in.txt", "r", stdin);a

    string line; int x = 0;
    while (true) {
        x++;
        vector <string> to_print;
        string dad, mum, child;
        cin >> dad >> mum >> child;

        if (dad[0] == 'E') {
            break;
        }

        printf("Case %d: ", x);
        // Child question mark
        if (child[0] == '?') {
            vector <string> alleleCombos, rhCombos;
            generateAlleleRhCombo(dad, mum, alleleCombos, rhCombos);

            for (const auto &alleleCombo : alleleCombos) {
                for (const auto &rhCombo : rhCombos) {

                    string bloodType;
                    getBloodType(alleleCombo, bloodType);

                    if (rhCombo == "++")
                        to_print.push_back(bloodType + '+');
                    if (rhCombo == "+-") {
                        to_print.push_back(bloodType + '+');
                        to_print.push_back(bloodType + '-');
                    }
                    if (rhCombo == "--") {
                        to_print.push_back(bloodType + "-");
                    }

                }
            }

            clean(to_print);

            cout << dad << " " << mum << " "; print_nice(to_print); cout << endl;

            continue;
        }

        string A1 = (mum[0] == '?') ? dad : mum;

        for (const auto &pos : allCombs) {
            if (non_child(A1, pos, child))
                to_print.emplace_back(pos);
        }

        if (mum[0] == '?') {
            cout << dad << " ";
            print_nice(to_print);
            cout << " " << child << endl;
        }

        if (dad[0] == '?') {
            print_nice(to_print);
            cout << " " << mum << " " << child << endl;
        }

    }
}


