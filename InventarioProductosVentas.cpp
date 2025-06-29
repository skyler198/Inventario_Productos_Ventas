#include <iostream>
#include <string>

using namespace std;

struct Producto {
	string nombre;
	float precio;
};

struct Venta {
    int idVenta;
    string producto;
    int cantidad;
    float precioTotal;
};

void menu(){
	char opcion;
	
	do{
		cout << "            ---------------MENU PRINCIPAL---------------\n" << endl;
			
		cout << "\n ---------------------------------------------------------------------\n";
		cout << "  a) Registrar un nuevo producto." << endl;
		cout << "  b) Listar los productos registrados." << endl;
		cout << "  c) Buscar un producto por nombre." << endl;
		cout << "  d) Actualizar los datos de un producto." << endl;
		cout << "  e) Eliminar un producto." << endl;
		cout << "  f) Registrar una venta." << endl;
		cout << "  g) Listar las ventas realizadas." << endl;
		cout << "  h) Calcular el total de ventas realizadas." << endl;
		cout << "  s) Salir del programa." << endl;
		cout << " ---------------------------------------------------------------------\n";
	
		cout << "\n  Elija una opcion: ";
		cin >> opcion;
		
		switch (opcion){
			case 'a':
				//registarProducto();
				break;
			case 'b':
				//listaProductosRegistrados();
				break;
			case 'c':
				//buscarProducto();
				break;
			case 'd':
				//ActualizarDatosProducto();
				break;
			case 'e':
				//eliminarProducto();
				break;
			case 'f':
				//registrarVenta();
				break;
			case 'g':
				//listarVentasRealizadas();
				break;
			case 'h':
				//CalcularTotalVentas();
				break;
			case 's':
				cout << "\n -----------------------------------------";
				cout << "\n  GRACIAS POR USAR MI PROGRAMA <3!" << endl;
				cout << "\n  Saliendo del programa ..." << endl;
				cout << "  PROGRAMA FINALIZADO!" << endl;
				system("pause");
				break;
			default:
				cout << "\n  INVALIDO, porfavor ingrese una opcion valida\n" << endl;
				system("pause");
				break;
				
		}
	}while (opcion != 's');
}


int main(){
	menu();
	
	return 0;
}