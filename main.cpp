#include <iostream>

#include <cstring>

using namespace std;
class VerifCastig
{//clasa in care urmaresc daca un meci este castigat sau nu
private:
    int castigare;
public:
    VerifCastig()
    {//initializez castigare cu 0, adica meciun nu este castigat. atunci cand castigare devine 1 cineva a castigat
        castigare=0;
    }
    VerifCastig &operator=(const VerifCastig & castigare)
    {
        this->castigare=1;
    }
    int getCastigare() const {
        return castigare;
    }

    void setCastigare(int castigare) {
        VerifCastig::castigare = castigare;
    }

    ~VerifCastig()=default;
};
class Mutare
{//in mutare tinem minte al cui este randul. Face cu schimbul intre 1 si 2..adica jucatorul 1 si 2
private:
    int mutare;
public:
    Mutare()=default;
    void setMutare(const int &mutare)
    {
        Mutare::mutare=mutare;
    }
    int getMutare() const
    {
        return mutare;
    }
    friend std::ostream &operator<<(std::ostream  &out, const Mutare &tura)
    {
        out<<tura.mutare;
    }

    ~Mutare()=default;
};
class Piesa
{//tinem cont de coloana pe care urmeaza sa punem piesa, care ulterior va cadea
private:
    int coloana_piesa;
public:
    Piesa()=default;
    int getPiesa() const
    {
        return coloana_piesa;
    }
    friend std::istream &operator>>(std::istream &in, Piesa &piesa)
    {
        in>>piesa.coloana_piesa;
        return in;
    }
    ~Piesa()=default;
};
class Jucator
{//tinem minte numele jucatorilor si punctajul(pentru partea 2 si 3)
private:
    string nume;
    //int punctaj;

public:
    Jucator()=default;

    Jucator(const Jucator&jucator)
    {
        this->nume=jucator.nume;
        //this->punctaj=jucator.punctaj;
    }
    friend std::istream &operator>>(std::istream &in, Jucator &jucator)
    {
        in>>jucator.nume;
        return in;
    }

    const string &getNume() const {
        return nume;
    }

    friend std::ostream &operator<<(std::ostream &out, const Jucator &jucator)
    {
        out<<jucator.nume<<endl;
        return out;
    }
    ~Jucator()=default;
};
class Tabla
{
private:
    char tabla[8][7];

public:
    Tabla()
    {//constructor: toate elementele cu ^ si pe prima linie notam coloanele pentru joc
        for(int i=1; i<8; i++)
            for(int j=0; j<7; j++)
                tabla[i][j]='^';
        for(int j=0; j<7; j++)
            tabla[0][j]='1'+j;
    }
    int verificare_jucator(int lin, int col)
    {
        //pe linie
        int nr=0;
        for(int j=0; j<6 && nr<3; j++)
            if((tabla[lin][j]==tabla[lin][j+1]) && tabla[lin][j]!='^' && tabla[lin][j+1]!='^')
                nr++;
            else nr=0;
        if(nr>=3) return 1;//castigator

        //pe coloana
        nr=0;
        for(int i=lin; i<7 && nr<3; i++)
            if((tabla[i][col]==tabla[i+1][col]) && tabla[i][col]!='^' && tabla[i+1][col]!='^')
                nr++;
            else nr=0;
        if(nr>=3) return 1;

        //pe diagonala in sensul / in jos
        nr=0;
        int egale=1;
        int i=lin, j=col;
        while(egale==1)
        {
            if(tabla[lin][col]==tabla[i+1][j-1])
            {
                nr++;
                i=i+1;
                j=j-1;
            }
            else egale=0;
        }
        //pe diagonala in sensul / in sus
        nr=0;
        egale=1;
        i=lin;
        j=col;
        while(egale==1)
        {
            if(tabla[lin][col]==tabla[i-1][j+1])
            {
                nr++;
                i=i-1;
                j=j+1;
            }
            else egale=0;
        }
        if(nr>=3) return 1; //castigator

        //pe diagonala in sensul \ in jos
        nr=0;
        egale=1;
        i=lin;
        j=col;
        while(egale==1)
        {
            if(tabla[lin][col]==tabla[i+1][j+1])
            {
                nr++;
                i=i+1;
                j=j+1;
            }
            else egale=0;
        }
        if(nr>=3)
            return 1;//castigator

        //pe diagonala in sensul  \ in sus
        nr=0;
        egale=1;
        i=lin;
        j=col;
        while(egale==1)
        {
            if(tabla[lin][col]==tabla[i-1][j-1])
            {
                nr++;
                i=i-1;
                j=j-1;
            }
            else egale=0;
        }
        return 0;//necastigator
    }
    void afisare()
    {
        for (int i=0; i<8; i++)
        {
            for(int j=0; j<7; j++)
                cout<<tabla[i][j]<<" ";
            cout<<endl;
        }
    }
    int coloanafull(int col)
    {
        if(tabla[1][col]!='^') return 0;//nu avem piesa pana sus
        return 1;//coloana e full
    }
    int gravitatie(int col)
    {//elementul se va pune pe linia 1 evident si coloana col, stiind asta o coboram pana jos sau pana la ultima piesa daca e
        int i=1;
        while(tabla[i+1][col-1]=='^')
        {
            swap(tabla[i][col-1], tabla[i+1][col-1]);
            i++;
        }
        return i;
    }
    void setElement(int col, char value)
    {//punem elementul value care poate fi o sau x depinde de jucator pe linia 1 si coloana ceruta urmand sa fie coborat
        if(col>=0 && col<7)
            tabla[1][col]=value;
    }
    ~Tabla()=default;
};


int main() {
    //Declarare jucatori si citirea numelor
    Jucator jucator1, jucator2;
    cout<<"Introduceti alias-ul primului jucator: ";
    operator>>(std::cin, jucator1);
    cout<<endl;
    cout<<"Introduceti alias-ul pentru al doilea jucator: ";
    operator>>(std::cin, jucator2);
    cout<<endl;

    //declar tabla de joc
    Tabla tabla_joc;
    tabla_joc.afisare();
    cout<<endl;

    //decalar mutarile, mereu incepe 1
    Mutare tura_jucator;
    tura_jucator.setMutare(1);


    Piesa coloana_coresp;//citim coloanele pe care punem piese


    VerifCastig castigare;//castigare=0, cand devine 1 cineva a castigat
    while(castigare.getCastigare()==0)
    {
        if(tura_jucator.getMutare()==1)
        {
            cout<<"Tura lui "<<jucator1.getNume()<<endl;

            cout<<"Indroduceti numarul coloanei dorite: ";
            operator>>(std::cin, coloana_coresp);
            while(coloana_coresp.getPiesa()-1<0 || coloana_coresp.getPiesa()-1>6 || tabla_joc.coloanafull(coloana_coresp.getPiesa()-1)==0)
            {//verificam daca coloana exista
                cout<<"Coloana inexistenta sau plina"<<endl;
                cout<<"Indroduceti numarul coloanei dorite: ";
                operator>>(std::cin, coloana_coresp);
            }
            cout<<endl;

            tabla_joc.setElement(coloana_coresp.getPiesa()-1, 'o');//punem elememtul pe coloana ceruta

            int t=tabla_joc.gravitatie(coloana_coresp.getPiesa()); //activam gravitatia pentru piesa pusa si in t pastram linia la care e pentru mai tarziu

            if(tabla_joc.verificare_jucator(t, coloana_coresp.getPiesa()-1))
                castigare.setCastigare(1);//verificam daca piesa a facut o miscare castigatoare

            tabla_joc.afisare();
            tura_jucator.setMutare(2);//mutam tura la jucatorul 2

            if(castigare.getCastigare()==1)
                cout<<"Felicitari "<<jucator1.getNume()<<"!!!!!";
        }
        else
        {
            cout<<"Tura lui "<<jucator2.getNume()<<endl;

            cout<<"Indroduceti numarul coloanei dorite: ";
            operator>>(std::cin, coloana_coresp);
            while(coloana_coresp.getPiesa()-1<0 || coloana_coresp.getPiesa()-1>6 || tabla_joc.coloanafull(coloana_coresp.getPiesa()-1)==0)
            {//verificam daca coloana exista
                cout<<"Coloana inexistenta sau plina"<<endl;
                cout<<"Indroduceti numarul coloanei dorite: ";
                operator>>(std::cin, coloana_coresp);
            }
            cout<<endl;
            tabla_joc.setElement(coloana_coresp.getPiesa()-1, 'x');
            int t=tabla_joc.gravitatie(coloana_coresp.getPiesa());
            if(tabla_joc.verificare_jucator(t, coloana_coresp.getPiesa()-1))
                castigare.setCastigare(1);
            tabla_joc.afisare();
            tura_jucator.setMutare(1);
            if(castigare.getCastigare()==1)
                cout<<"Felicitari "<<jucator2.getNume()<<"!!!!!";
        }

    }

    return 0;
}
