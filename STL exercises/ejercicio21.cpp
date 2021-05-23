#include <iostream>
#include <string>
#include <list>
#include <set>
#include <map>

using namespace std;

struct Paciente
{
    string nombre, apellidos, DNI;
    int gravedad; //DONDE A MAYOR GRAVEDAD MAYOR PRIORIDAD
    bool operator()(Paciente p1, Paciente p2) const
    {
        return p1.gravedad < p2.gravedad;
    }
};

ostream &operator<<(ostream &f, const Paciente &pac)
{
    f << "DATOS DEL PACIENTE::" << endl
      << "NOMBRE->" << pac.nombre << endl
      << "APELLIDOS->" << pac.apellidos << endl
      << "DNI->" << pac.DNI << endl
      << "GRAVEDAD->" << pac.gravedad << endl;
    return f;
}

typedef multiset<Paciente, Paciente> orden_Urg;
typedef map<string, orden_Urg::iterator> dicc_DNI;

class Urgencias
{
private:
    orden_Urg pacientes;
    dicc_DNI save_Dni;

public:
    Paciente getPorDni(string DNI);
    void addPaciente(Paciente nuevo);
    void borraPaciente(string DNI);
    void mostrarUrgencias();
};

void Urgencias::mostrarUrgencias()
{
    orden_Urg::iterator it;
    for (it = pacientes.begin(); it != pacientes.end(); it++)
    {
        cout << "-------------------------------" << endl;
        cout << *it;
    }
}

void Urgencias::addPaciente(Paciente nuevo)
{
    orden_Urg::iterator it;
    it = (pacientes.insert(nuevo));
    this->save_Dni.insert(dicc_DNI::value_type(nuevo.DNI, it));
}

void Urgencias::borraPaciente(string DNI)
{
    orden_Urg::iterator it;
    it = save_Dni[DNI];
    pacientes.erase(*it);
    //SE ME OLVIDÓ
    this->save_Dni.erase(DNI);
}

Paciente Urgencias::getPorDni(string DNI)
{
    return *(save_Dni[DNI]);
}

int main()
{
    Paciente P1, P2, P3, P4, P5;
    P1.nombre = "PEDRO";
    P2.nombre = "MARC";
    P3.nombre = "ALEX";
    P4.nombre = "LUCA";
    P5.nombre = "LEO";
    P1.apellidos = "SANCHEZ";
    P2.apellidos = "DOMENECH";
    P3.apellidos = "GUIRADO";
    P4.apellidos = "DONCINC";
    P5.apellidos = "MESSI";
    P1.DNI = "24539857G";
    P2.DNI = "78236103F";
    P3.DNI = "36829538L";
    P4.DNI = "14273849D";
    P5.DNI = "54930239F";
    P1.gravedad = 1;
    P2.gravedad = 0;
    P3.gravedad = 9;
    P4.gravedad = 3;
    P5.gravedad = 10;
    Urgencias hospital;
    hospital.addPaciente(P1);
    hospital.addPaciente(P1);
    hospital.addPaciente(P2);
    hospital.addPaciente(P3);
    hospital.addPaciente(P4);
    hospital.addPaciente(P5);

    hospital.mostrarUrgencias();

    cout << "-------------------------------" << endl
         << "PRUEBA EXTRA" << endl
         << hospital.getPorDni("54930239F")
         << "-------------------------------" << endl
         << hospital.getPorDni("14273849D");
}
