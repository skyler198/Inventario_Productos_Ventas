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

void registrarProducto(Producto productos[], int &cantidad){
	
	cout << "Ingrese los datos del producto #" << cantidad + 1 << " a registrar :" << endl;
	
	cout << "\nNombre del producto: ";
	cin.ignore();
	getline(cin, productos[cantidad].nombre);

	cout << "Precio del producto: ";
	cin >> productos[cantidad].precio;
	
	cantidad++;

}

void listaProductosRegistrados(Producto productos[], int &cantidad){
	
	cout << "Lista de productos registrados:" << endl;
	
	for (int i = 0; i < cantidad; i++){
		cout << "\n  ------------------------ \n";
		cout << " |" << i + 1 << ". Nombre: " << productos[i].nombre << "    |" << endl;
		cout << " | precio s/.: " << productos[i].precio << "        |" << endl;
		cout << "  ------------------------ \n";
	}
	
}


void menu(){
	char opcion;
	const int TAM = 100;
	Producto productos[TAM];
	int cantidadProducto = 0;
	
	do{
		cout << "\n   ---------------MENU PRINCIPAL---------------" << endl;
			
		cout << "\n  ----------------------------------------------- \n";
		cout << " | a) Registrar un nuevo producto.               |" << endl;                              
		cout << " | b) Listar los productos registrados.          |" << endl;
		cout << " | c) Buscar un producto por nombre.             |" << endl;
		cout << " | d) Actualizar los datos de un producto.       |" << endl;
		cout << " | e) Eliminar un producto.                      |" << endl;
		cout << " | f) Registrar una venta.                       |" << endl;
		cout << " | g) Listar las ventas realizadas.              |" << endl;
		cout << " | h) Calcular el total de ventas realizadas.    |" << endl;
		cout << " | s) Salir del programa.                        |" << endl;
		cout << "  -----------------------------------------------\n";
	
		cout << "\n  Elija una opcion: ";
		cin >> opcion;
		
		switch (opcion){
			case 'a':
				registrarProducto(productos, cantidadProducto);
				system("pause");
				break;
			case 'b':
				listaProductosRegistrados(productos, cantidadProducto);
				system("pause");
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
				system("pause");
				cout << "  PROGRAMA FINALIZADO!" << endl;
				
				break;
			default:
				cout << "\n  INVALIDO, porfavor ingrese una opcion valida\n" << endl;
				system("pause");
				break;		
		}
		system("cls");
	}while (opcion != 's');
}


int main(){
	menu();
	
	return 0;
}