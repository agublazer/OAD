#include<iostream>
using namespace std;

float convertir_minutos(float hora)
{
    int hora_1 = hora;
    return hora_1*60 + (hora - hora_1)*100;
}

void convertir_horas(int minutos,bool formato)
{
    float hora;
    float minutos_1 = (minutos%60);
    hora = minutos/60;
    if (formato==true)
    {
		if ( hora < 10 )
			cout << "0";
		cout << hora << ":";
		if ( minutos_1 < 10)
			cout << "0";
		cout << minutos_1;	
    }
    if (formato==false)
    {
        if (hora > 12 and minutos_1 < 10)
            cout << hora-12 << ":" << "0" << minutos_1 << " pm";
        if (hora > 12 and minutos_1 >= 10)
            cout << hora-12 << ":" << minutos_1 << " pm";
        if (hora <= 12 and minutos_1 < 10)
            cout << hora << ":" << "0" << minutos_1 << " am";
        if (hora <= 12 and minutos_1 >= 10)
            cout << hora << ":" << minutos_1 << " am";

    }

}

void imprimir_horario(float minutos_entrada, float minutos_salida, float duracion_hora, bool formato_hora)
{
    float minutos_total = minutos_salida - minutos_entrada;
    float total_horas = (float)(minutos_salida - minutos_entrada)/(float)(duracion_hora);
    float hora_1,hora_2;

    if (minutos_total<=0 or minutos_total<duracion_hora)
        cout<<"Horario no valido"<<endl;
    else
    {
        hora_1=minutos_entrada;
        for(int i=0;i<total_horas;i++)
        {
            hora_2= hora_1+duracion_hora;
            if (hora_2<=minutos_salida)
            {
                convertir_horas(hora_1,formato_hora);
                cout<<" - ";
                convertir_horas(hora_2,formato_hora);
                cout<<endl;
            }
            hora_1=hora_2;
        }
    }
}
int main()
{
    //variables de entrada:
    float hora_inicio;
    float hora_fin;
    float duracion_hora;
    bool formato_hora;

    cout<<"Datos: "<<endl;
    cout<<"Inicio: ";cin>>hora_inicio;
    cout<<"Fin: ";cin>>hora_fin;
    cout<<"Duracion: ";cin>>duracion_hora;
    cout<<"Formato hora: (0=am/pm,1=normal)";cin>>formato_hora;

    float minutos_inicio = convertir_minutos(hora_inicio);
    float minutos_fin = convertir_minutos(hora_fin);

    imprimir_horario(minutos_inicio,minutos_fin,duracion_hora,formato_hora);




}
