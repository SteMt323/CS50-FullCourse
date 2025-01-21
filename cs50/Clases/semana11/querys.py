import sqlite3

conn = sqlite3.connect("ejemplo.db")

conn.row_factory = sqlite3.Row

db = conn.cursor()


db.execute('''
           CREATE TABLE IF NOT EXISTS Estudiantes
           ( id INTEGER PRIMARY KEY,
           nombre VARCHAR(50) NOT NULL,
           carrera VARCHAR(50) NOT NULL
           )'''
           )

nombre = input("Ingrese su nombre: ")
carrera = input("Ingrese su carrera: ")

db.execute('''INSERT INTO Estudiantes(nombre, carrera)
           VALUES(?,?)
           ''', (nombre, carrera),
          )

conn.commit()


#if resultado:
#    print(f"{resultado['nombre: ]} esta en la carrera {resultado['carrera: ]}")
#else:
    #print("")



conn.close()
