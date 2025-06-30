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
		cout << "\n  ------------------------- \n";
		cout << " | " << i + 1 << ". Nombre: " << productos[i].nombre << "    |" << endl;
		cout << " |    precio s/.: " << productos[i].precio << "      |" << endl;
		cout << "  ------------------------- \n";
	}
	
}

void buscarProducto(Producto productos[], int cantidad){
	
    string nombreBuscado;

    cout << "\nbuscar producto:\n" << endl;
    cin.ignore(); 
    cout << "Nombre del producto: ";
    getline(cin, nombreBuscado);

    for (int i = 0; i < cantidad; i++) {
        if (productos[i].nombre == nombreBuscado) {
            cout << "\n  ------------------------- \n";
            cout << " | " << i + 1 << ". Nombre: " << productos[i].nombre << "    |" << endl;
            cout << " |    precio S/.: " << productos[i].precio << "      |" << endl;
            cout << "  ------------------------- \n";

            break; // Termina la búsqueda al encontrar el producto
        }
    }
}

void ActualizarDatosProducto(Producto productos[], int cantidad){
	
	int opcion;

	cout << "Actualizar productos:" << endl;
	for (int i = 0; i < cantidad; i++){
		cout << i + 1 << ") Nombre: " << productos[i].nombre << " -- Precio S/.: " << productos[i].precio << endl;
	}
	
	do {
		cout << "Ingrese el numero del producto que desea actualizar: " << endl;
		cin.ignore();
		cin >> opcion;
		
		if (opcion >= 1 && opcion <= cantidad){
			
			int posicion = opcion - 1;
			
			cin.ignore(); //limpia el salto de línea pendiente del cin anterior nwn
			cout << "Nuevo nombre del producto (nombre actual: " << productos[posicion].nombre << "): ";
		    getline(cin, productos[posicion].nombre);
		
		    cout << "Nuevo precio del producto (precio actual: S/. " << productos[posicion].precio << "): ";
		    cin >> productos[posicion].precio;
		
		    cout << "\nProducto actualizado correctamente.\n";	
		} else {
			cout << "Opcion invalida, intentelo de nuevo" << endl;
			system("pause"); // pausa para que el usuario lea el mensaje
			system("cls"); // limpiar pantalla
			
			cout << "Actualizar productos:" << endl;
			for (int i = 0; i < cantidad; i++){
				cout << i + 1 << ") Nombre: " << productos[i].nombre << " -- Precio S/.: " << productos[i].precio << endl;
			}
		}
	}while (opcion < 1 || opcion > cantidad);
}

void eliminarProducto(Producto productos[], int &cantidad){
	int opcion;
	cout << "Eliminar Producto:" << endl;
	
	for (int i = 0; i < cantidad; i++){
		cout << i + 1 << ") Nombre: " << productos[i].nombre << " -- Precio S/.: " << productos[i].precio << endl;
	}
	
	cout << "Ingrese el numero del producto que desea eliminar: ";
	cin >> opcion;
	
	for (int i = opcion - 1; i < cantidad - 1; i++) {
        productos[i] = productos[i + 1];
    }
	cout << "Producto eliminado correctamente" << endl;
	
	cantidad--;
}

void registrarVenta(Venta ventas[], int &cantidadVentas, Producto productos[], int cantidadProducto){
	
	cout << "Registrar venta" << endl;
	cout <<"\nLista de productos disponibles para venta:" << endl;
	
	for (int i = 0; i < cantidadProducto; i++){
		cout << "\n  ------------------------- \n";
		cout << " | " << i + 1 << ". Nombre: " << productos[i].nombre << "    |" << endl;
		cout << " |    precio s/.: " << productos[i].precio << "      |" << endl;
		cout << "  ------------------------- \n";
	}
	
	int opcion;
    cout << "Seleccione el numero del producto a vender: ";
    cin >> opcion;
    
    int posicion = opcion - 1;
    int cantidadVendida;

    cout << "Ingrese la cantidad que se vendio del producto seleccionado: ";
    cin >> cantidadVendida;
    
    // Registramos la venta
    ventas[cantidadVentas].idVenta = cantidadVentas + 1;
    ventas[cantidadVentas].producto = productos[posicion].nombre;
    ventas[cantidadVentas].cantidad = cantidadVendida;
    ventas[cantidadVentas].precioTotal = productos[posicion].precio * cantidadVendida;

    cout << "\nVenta registrada correctamente." << endl;
    cout << "|  Producto: " << ventas[cantidadVentas].producto << endl;
    cout << "|  Cantidad: " << ventas[cantidadVentas].cantidad << endl;
    cout << "|  Total: S/. " << ventas[cantidadVentas].precioTotal << endl;

    cantidadVentas++;
}

void listarVentasRealizadas(Venta ventas[], int cantidadVenta){
	
	cout << "\nlistado de ventas realizadas\n";

    for (int i = 0; i < cantidadVenta; i++) {
        cout << "\n------------------------------";
        cout << "\nVenta #" << ventas[i].idVenta;
        cout << "\nProducto: " << ventas[i].producto;
        cout << "\nCantidad: " << ventas[i].cantidad;
        cout << "\nTotal: S/. " << ventas[i].precioTotal;
        cout << "\n------------------------------\n";
    }
}

void calcularTotalVentas(Venta ventas[], int cantidadVenta){
	
	float totalGeneral = 0;

    for (int i = 0; i < cantidadVenta; i++) {
        totalGeneral += ventas[i].precioTotal;
    }
	
	cout << "\n------------------------------------------";
    cout << "\nTotal de ventas: S/. "<< totalGeneral;
    cout << "\n------------------------------------------\n";

	
}

void menu(){
	char opcion;
	const int TAM = 100;
	Producto productos[TAM];
	int cantidadProducto = 0;
	Venta ventas [TAM];
	int cantidadVenta = 0;
	
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
				buscarProducto(productos, cantidadProducto);
				system("pause");
				break;
			case 'd':
				ActualizarDatosProducto(productos, cantidadProducto);
				system("pause");
				break;
			case 'e':
				eliminarProducto(productos, cantidadProducto);
				system("pause");
				break;
			case 'f':
				registrarVenta(ventas, cantidadVenta, productos, cantidadProducto);
				system("pause");
				break;
			case 'g':
				listarVentasRealizadas(ventas, cantidadVenta);
				system("pause");
				break;
			case 'h':
				calcularTotalVentas(ventas, cantidadVenta);
				system("pause");
				break;
			case 's':
				cout << "\n -----------------------------------------";
				cout << "\n  GRACIAS POR USAR MI PROGRAMA <3!" << endl;
				cout << "\n  Saliendo del programa ..." << endl;
				system("pause");
				cout << "  PROGRAMA FINALIZADO!" << endl;
				system("pause");
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