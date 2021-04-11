#include <mysql.h>
#include <iostream>
#include <string>

using namespace std;
void ins_m();
void mos_m();
void mod_m();
void eli_m();
void ins_p();
void mos_p();
void mod_p();
void eli_p();
int q_estado;

int main()
{
	int x, y;
	do {
		system("cls");
		cout << "--MENU PRINCIPAL Tablas--\n";
		cout << "---Seleccione la tabla---\n";
		cout << "1- Marcas\n";
		cout << "2- Productos\n";
		cout << "3- Salir\n";
		cin >> x;
		switch (x)
		{
		case 1:
			do {
				system("cls");
				cout << "1- Insertar Marcas\n";
				cout << "2- Ver Marcas\n";
				cout << "3- Modificar Marcas\n";
				cout << "4- Eliminar Marcas\n";
				cout << "5- Menu Tablas\n";
				cin >> y;
				switch (y)
				{
				case 1:
					ins_m();
					break;
				case 2:
					mos_m();
					break;
				case 3:
					mod_m();
					break;
				case 4:
					eli_m();
					break;
				}
			} while (y != 5);
			break;
		case 2:
			do {
				system("cls");
				cout << "1- Insertar Productos\n";
				cout << "2- Ver Productos\n";
				cout << "3- Modificar Productos\n";
				cout << "4- Eliminar Productos\n";
				cout << "5- Menu Tablas\n";
				cin >> y;
				switch (y)
				{
				case 1:
					ins_p();
					break;
				case 2:
					mos_p();
					break;
				case 3:
					mod_p();
					break;
				case 4:
					eli_p();
					break;
				default:
					break;
				}
			} while (y != 5);
			break;
		default:
			break;
		}
	} while (x != 3);
	system("pause");
	return 0;
}
void ins_m() {
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "wm123#", "db_empresa", 3306, NULL, 0);
	if (conectar) {
		system("cls");
		cout << "Conexion exitosa\n";
		string marca;
		cout << "Ingrese la marca:\n";
		cin.ignore();
		getline(cin, marca);
		string insert = "insert into marcas(marca) values('" + marca + "')";
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);
		if (!q_estado) {
			cout << "Marca Ingresada exitosamente\n";
		}
		else {
			cout << "Error al ingresar marca\n";
		}
	}
	else {
		system("cls");
		cout << "Error en la conexion\n";
	}
	system("pause");
}

void mos_m() {
	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "wm123#", "db_empresa", 3306, NULL, 0);
	if (conectar) {
		system("cls");
		cout << "Conexion exitosa\n";
		string consulta = "select * from marcas";
		const char* c = consulta.c_str();
		q_estado = mysql_query(conectar, c);
		if (!q_estado) {
			cout << "ID - MARCA\n";
			resultado = mysql_store_result(conectar);
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << " - " << fila[1] << endl;
			}
		}
		else {
			cout << "Error al realizar consulta\n";
		}
	}
	else {
		system("cls");
		cout << "Error en la conexion\n";
	}
	system("pause");
}

void mod_m() {
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "wm123#", "db_empresa", 3306, NULL, 0);
	if (conectar) {
		system("cls");
		cout << "Conexion exitosa\n";
		string idmarca, marca;
		cout << "Ingrese el id de la marca que desea modificar\n";
		cin >> idmarca;
		cout << "ingrese el nuevo nombre de la marca\n";
		cin.ignore();
		getline(cin, marca);
		string modificar = "update marcas set marca = '" + marca + "' where idmarca =" + idmarca + "";
		const char* m = modificar.c_str();
		q_estado = mysql_query(conectar, m);
		if (!q_estado) {cout << " La modificacion de la marca se ha realizado exitosamente\n";}
		else {cout << "!Error¡ no se pudo modificar\n";}}
	else {
		system("cls");
		cout << "Error en la conexion\n";
	}
	system("pause");
}

void eli_m() {
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "wm123#", "db_empresa", 3306, NULL, 0);
	if (conectar) {
		system("cls");
		cout << "Conexion exitosa\n";
		string idmarca;
		cout << "Ingrese el id de la marca que desea eliminar\n";
		cin >> idmarca;
		string eliminar = "delete from marcas where idmarca =" + idmarca + "";
		const char* d = eliminar.c_str();
		q_estado = mysql_query(conectar, d);
		if (!q_estado) {
			cout << "Su marca se ha eliminado exitosamente\n";
		}
		else {
			cout << "!Error¡ no se pudo eliminar\n";
		}
	}
	else {
		system("cls");
		cout << "Error en la conexion\n";
	}
	system("pause");
}

void ins_p() {
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "wm123#", "db_empresa", 3306, NULL, 0);
	if (conectar) {
		system("cls");
		cout << "Conexion exitosa\n";
		string producto, descripcion;
		string idmarca, existencia;
		string precio_costo, precio_venta;
		string fecha_ingreso = "now()";
		cout << "Ingrese el producto:\n";
		cin.ignore();
		getline(cin, producto);
		cout << "Ingrese el idmarca:\n";
		cin >> idmarca;
		cout << "Ingrese descripcion:\n";
		cin.ignore();
		getline(cin, descripcion);
		cout << "Ingrese precio de costo:\n";
		cin >> precio_costo;
		cout << "Ingrese precio de venta:\n";
		cin >> precio_venta;
		cout << "Ingrese la cantidad de existencias:\n";
		cin >> existencia;
		string insert = "insert into productos(producto,idmarca,descripcion,precio_costo,precio_venta,existencia,fecha_ingreso) values('" + producto + "'," + idmarca + ", '" + descripcion + "', " + precio_costo + ", " + precio_venta + ", " + existencia + ", " + fecha_ingreso + ")";
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);
		if (!q_estado) {
			cout << "Su prodcuto se ingreso exitosamente\n";
		}
		else {
			cout << "!Error¡no se puede ingresar el producto.\n";
		}
	}
	else {
		system("cls");
		cout << "Error en la conexion\n";
	}
	system("pause");
}

void mos_p() {
	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "wm123#", "db_empresa", 3306, NULL, 0);
	if (conectar) {
		system("cls");
		cout << "Conexion exitosa\n";
		string consulta = "select * from productos";
		const char* c = consulta.c_str();
		q_estado = mysql_query(conectar, c);
		if (!q_estado) {
			cout << "ID - PRODUCTO - IDMARCA - DESCRIPCION - PRECIO COSTO - PRECIO VENTA - EXISTENCIA - FECHA INGRESO\n";
			resultado = mysql_store_result(conectar);
			while (fila = mysql_fetch_row(resultado)) {
				for (int j = 0; j < 8; j++) {
					cout << " - " << fila[j];
				}
				cout << "<\n";
			}
		}
		else {
			cout << "Error al consultar\n";
		}
	}
	else {
		system("cls");
		cout << "Error en la conexion\n";
	}
	system("pause");
}

void mod_p() {
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "wm123#", "db_empresa", 3306, NULL, 0);
	if (conectar) {
		system("cls");
		cout << "Conexion exitosa\n";
		string idproducto, producto, descripcion, idmarca, existencia, precio_costo, precio_venta;
		cout << "Ingrese el id del registro que desea modificar\n";
		cin >> idproducto;
		cout << "Ingrese el nuevo nombre del producto\n";
		cin.ignore();
		getline(cin, producto);
		cout << "Ingrese la nueva descripcion\n";
		cin.ignore();
		getline(cin, descripcion);
		cout << "Ingrese el nuevo idmarca\n";
		cin >> idmarca;
		cout << "Ingrese el nuevo precio costo\n";
		cin >> precio_costo;
		cout << "Ingrese el nuevo precio venta\n";
		cin >> precio_venta;
		cout << "Ingrese la nueva cantidad de existencias\n";
		cin >> existencia;
		string modificar = "update productos set producto = '" + producto + "', idmarca = " + idmarca + ", descripcion = '" + descripcion + "', precio_costo = " + precio_costo + ", precio_venta = " + precio_venta + ", existencia = " + existencia + " where idproducto =" + idproducto + "";
		const char* m = modificar.c_str();
		q_estado = mysql_query(conectar, m);
		if (!q_estado) {
			cout << "Su producto se ha modificado exitosamente\n";
		}
		else {
			cout << "!Error¡ no se puede modificar el producto\n";
		}
	}
	else {
		system("cls");
		cout << "Error en la conexion\n";
	}
	system("pause");
}

void eli_p() {
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "wm123#", "db_empresa", 3306, NULL, 0);
	if (conectar) {
		system("cls");
		cout << "Conexion exitosa\n";
		string idproducto;
		cout << "Ingrese el id del producto que desea eliminar\n";
		cin >> idproducto;
		string eliminar = "delete from productos where idproducto =" + idproducto + "";
		const char* d = eliminar.c_str();
		q_estado = mysql_query(conectar, d);
		if (!q_estado) {
			cout << "Su producto se ha eliminado exitosamente\n";
		}
		else {
			cout << "!Error¡ no se pudo eliminar\n";
		}
	}
	else {
		system("cls");
		cout << "Error en la conexion\n";
	}
	system("pause");
}

