#include <iostream>
#include <string>

using namespace std;

class Nodo{
    Nodo *sig;
    string matricula;
    string nombre;
    int semestre;
    public:
    Nodo();
    //~Nodo();
    void setSig(Nodo *sig);
    Nodo * getSig(); 
    string getMatricula();
    void setMatricula(string xmatricula);
    string getNombre();
    void setNombre(string xnombre);
    int getSemestre();
    void setSemestre(int xsemestre);

};

Nodo::Nodo(){
    sig = NULL;
    nombre = "\0";
    matricula = "\0";
    semestre = 0;
}


void Nodo::setMatricula(string xmatricula){
    this->matricula = xmatricula;

}
string Nodo::getMatricula(){
    return matricula;
}
void Nodo::setNombre(string xnombre){
    this->nombre = xnombre;
}
string Nodo::getNombre(){
    return nombre;
}
void Nodo::setSemestre(int xsemestre){
    this->semestre=xsemestre;
}
int Nodo::getSemestre(){
    return semestre;
}
void Nodo::setSig(Nodo *sig){
    this->sig = sig;
}

Nodo * Nodo::getSig(){
    return sig;
}
class Lista{
    Nodo * cab;
    public:
    Lista();
    ~Lista();//la cosita se hace alt gr + *
    //Metodos basicos
    void insertarInicio();
    void insertarMatricula();
    void insertarSemestre();
    void insertarNombre();
    void eliminar();//Aqui al menos se hace desde la cabeza, no hace falta pasar posicion o asi
    int estaVacia();
    //int getDato();
    //Metodos complementarios
    void mostrar();
    int getFinal();
    int getMayor();
    //void insertarFinal(int x);
    void eliminarFinal();
    
   
};
Lista::Lista(){
    cab = NULL;
}
int Lista::estaVacia(){
    if (cab==NULL){
        return 1;
    }else{
        return 0;
    }
}
void Lista::insertarInicio(){
    Nodo *p;
    string matri,nom;
    
    int sem;
    cout<<"Ingresa la matricula: ";
    cin>>matri;
    cout<<"Ingresa el nombre: ";
    cin.ignore();
    getline(cin,nom);
    cout<<"Ingresa el semestre: ";
    cin>>sem;
    p=new Nodo;
    p->setMatricula(matri);
    p->setNombre(nom);
    p->setSemestre(sem);
    p->setSig(cab);
    cab = p;
}

void Lista::insertarMatricula(){
    Nodo *p;
    string matri,nom;
    
    int sem;
    cout<<"Ingresa la matricula: ";
    cin>>matri;
    cout<<"Ingresa el nombre: ";
    cin.ignore();
    getline(cin,nom);
    cout<<"Ingresa el semestre: ";
    cin>>sem;
    p=new Nodo;
    p->setMatricula(matri);
    p->setNombre(nom);
    p->setSemestre(sem);
    p->setSig(cab);
    cab = p;
}
void Lista::insertarNombre(){
    Nodo *p;
    string matri,nom;
    
    int sem;
    cout<<"Ingresa la matricula: ";
    cin>>matri;
    cout<<"Ingresa el nombre: ";
    cin.ignore();
    getline(cin,nom);
    cout<<"Ingresa el semestre: ";
    cin>>sem;
    p=new Nodo;
    p->setMatricula(matri);
    p->setNombre(nom);
    p->setSemestre(sem);
    p->setSig(cab);
    cab = p;
}

void Lista::insertarSemestre(){
    Nodo *p;//esta funcion es insertar inicio 
        
        
    string matri,nom;
    int sem;
    cout<<"Ingresa la matricula: ";
    cin>>matri;
    cout<<"Ingresa el nombre: ";
    cin.ignore();
    getline(cin,nom);
    cout<<"Ingresa el semestre: ";
    cin>>sem;
    p=new Nodo;
    p->setMatricula(matri);
    p->setNombre(nom);
    p->setSemestre(sem);
    
    if(estaVacia()){//Si la lista esta vacia se inserta al principio
        
        p->setSig(cab);
        cab = p;
    }
    else{//la lista solo tiene un elemento
        if(cab->getSig()==NULL && cab->getSemestre()>=sem){//Si el unico elemnto de la lista es mayor el nuevo se agrega al principio
            p->setSig(cab);
            cab = p;
        }
        else{
        if(cab->getSig()==NULL && cab->getSemestre()<=sem){//si el unico elemento de la lista es menor el nuevo se agrega al final 
            p->setSig(NULL);
            cab->setSig(p);
        }
        else{//la lista tiene mas de un elemento
            Nodo *q = cab;
            Nodo *aux;
            while(q->getSig()!=NULL){
                if(q->getSig()->getSemestre()<=sem){
                    aux=q->getSig();
                    q->setSig(p);
                    p->setSig(aux);
                    
                }
                
                //q=q->getSig();
                if(q->getSig()==NULL && q->getSemestre()>=sem){//si el semestre es mayor a todos los de la lista
                    p->setSig(q);
                    q->setSig(NULL);
                }
                q=q->getSig();
            }
        }
        }
    }
}

void Lista::mostrar(){
    
    Nodo *p;
    p = cab;
    while (p!=NULL){
        cout<<"----------------------------------- \n";
        cout<<"Matricula: "<<p->getMatricula()<<"\n";
        cout<<"Nombre: "<<p->getNombre()<<"\n";
        cout<<"Semestre: "<<p->getSemestre()<<"\n";
        p = p->getSig();
    }
    
}
Lista::~Lista(){
    Nodo *p;
    p=cab;
    while(cab!=NULL){
        cab = cab->getSig();
        delete p;
        p=cab;
    }
}    
int Lista::getMayor(){
    Nodo *p;
    p = cab;
    if (p==NULL){
    return -1;
    }
    int may;
    may = p->getSemestre();
    while (p!=NULL){
        if (may<p->getSemestre()){
            may=p->getSemestre();
            
        }
        p = p->getSig();
    }
    return may;
    }

void Lista::eliminar(){
    if (cab!=NULL){
    Nodo *p;
    p=cab;
    cab = cab->getSig();
    delete p;
    }
    
}
/*void Lista::insertarFinal(string matri,string nombre, int sem){
    Nodo * q;
    q = new Nodo;
    q->setDato(x);
    if (estaVacia()){
        cab = q;
    }
    Nodo *p;
    p = cab;
    while(p->getSig()!=NULL){
        p=p->getSig();
    }
    p->setSig(q);
}*/
int main (){
    int n,r,op;
    Lista lista;
    cout<<"Ingresa el numero de tutorados para iniciar: ";
    cin>>n;
    cout<<"¿Que atributo desea priorizar para la insercion?\n";
    cout<<"1.-Matricula \n 2.-Nombre \n 3.- Semestre \n";
    cin>>r;
    switch (r)
    {
    case 1:
        cout<<"Piorizar matricula \n";
        for(int i=0;i<n;i++){
            cout<<"Ingresa los datos del alumno "<<i+1<<"\n";
            lista.insertarMatricula();
        }
        break;
    case 2:    
        cout<<"Priorizar nombre";
        for(int i=0;i<n;i++){
            cout<<"Ingresa los datos del alumno "<<i+1<<"\n";
            lista.insertarNombre();
        }
        break;
    case 3:
        cout<<"Priorizar semestre";
        for(int i=0;i<n;i++){
            cout<<"Ingresa los datos del alumno "<<i+1<<"\n";
            lista.insertarSemestre();
        }
        break;
    default:
        cout<<"Error numero no valido, se usara la prioridad por defecto";
        r=1;
        for(int i=0;i<n;i++){
            cout<<"Ingresa los datos del alumno "<<i+1<<"\n";
            lista.insertarMatricula();
        }
        break;
    }
    bool val=true;
    
    while(val){
        cout<<"Menu principal\n";
        cout<<"La R es"<< r<<"\n";
        cout<<"1.-Insertar nuevo tutorado \n 2.-Eliminar tutorado \n 3.- Mostrar lista de tutorados \n 4.-Salir \n";
        
        cin>>op;
        
        switch (op)
        {
        case 1:
           cout<<"Insertar \n";
            if(r==1){
                lista.insertarMatricula();
            }
            else{
                if(r==2){
                lista.insertarNombre();
                }
                else{
                    lista.insertarSemestre();
                }
            }
            
            break;
        case 2:
          cout<<"Eliminar";
            break;
        case 3:
         cout<<"Lista de tutorados \n";
            lista.mostrar();
            break;
        case 4:
            cout<<"Salir";
            val=false;
            break;
     default:
         cout<<"Error opcion no valida, intente de nuevo";
         break;
      }
    
}
}