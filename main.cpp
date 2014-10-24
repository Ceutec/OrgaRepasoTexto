#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class Mascota
{
public:
    string nombre;
    int edad;
    Mascota(string nombre, int edad)
    {
        this->nombre=nombre;
        this->edad=edad;
    }
};

list<Mascota*>mascotas;

void escribirMascota(Mascota*mascota, string nombre_archivo)
{
    ofstream out(nombre_archivo.c_str(), ios::app);
    out<<mascota->nombre;
    out<<" ";
    out<<mascota->edad;
    out<<"\n";
    out.close();
}

void guardar(string nombre_archivo)
{
    ofstream out(nombre_archivo.c_str());
    out.close();
    for(list<Mascota*>::iterator i=mascotas.begin();
            i!=mascotas.end();
            i++)
        escribirMascota(*i,nombre_archivo);
}

void abrir(string nombre_archivo)
{
    mascotas.clear();
    ifstream in(nombre_archivo.c_str());
    string nombre;
    int edad;
    while(in>>nombre)
    {
        in>>edad;
        mascotas.push_back(new Mascota(nombre,edad));
    }
}

void imprimir()
{
    for(list<Mascota*>::iterator i=mascotas.begin();
            i!=mascotas.end();
            i++)
    {
        cout<<"Nombre: "<<(*i)->nombre<<" ";
        cout<<"Edad: "<<(*i)->edad<<endl;
    }
}

void agregarMascota(Mascota* mascota)
{
    mascotas.push_back(mascota);
}

int main()
{
    int opcion=0;
    do
    {
        cout<<"Menu"<<endl;
        cout<<"1. Abrir"<<endl;
        cout<<"2. Guardar"<<endl;
        cout<<"3. Agregar"<<endl;
        cout<<"4. Imprimir"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;

        switch(opcion)
        {
            case 1:
            {
                cout<<"Seleccione el archivo: ";
                string nombre_archivo;
                cin>>nombre_archivo;
                abrir(nombre_archivo);
            }
            break;
            case 2:
            {
                cout<<"Seleccione el archivo: ";
                string nombre_archivo;
                cin>>nombre_archivo;
                guardar(nombre_archivo);
            }
            break;
            case 3:
            {
                cout<<"Nombre: ";
                string nombre;
                cin>>nombre;
                cout<<"Edad: ";
                int edad;
                cin>>edad;
                Mascota* mascota = new Mascota(nombre,edad);
                agregarMascota(mascota);
            }
            break;
            case 4:
                imprimir();
            break;
        }

    }while(opcion!=5);

    return 0;
}
