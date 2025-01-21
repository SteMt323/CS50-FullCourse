-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Para saber la escena de crimen exacta.
SELECT * FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND year = 2023 AND street LIKE '%Humphrey%';


--CONSULTAS a interviews
--Para estar al tanto de los testimonios ocurridos el día del crimen
SELECT * FROM interviews
WHERE day = 28 AND month = 7 AND year = 2023;

SELECT transcript FROM interviews
WHERE day = 28 AND month = 7 AND year = 2023;

SELECT * FROM interviews
WHERE transcript LIKE '%bakery%';



--CONSULTAS de transacciones
--Eugene ID: 162, menciona que no sabe el nombre del ladron, pero lo vio sacar dinero en un cajero automático en Leggett Street.
SELECT * FROM atm_transactions
WHERE day = 28 AND month = 7 AND year = 2023 AND atm_location = 'Leggett Street';

--Una vez teniendo los registros dados en dicho ATM, consultaremos en bank_accounts
SELECT * FROM bank_accounts
WHERE account_number IN (28500762, 28296815, 76054385, 49610011, 16153065, 86363979, 25506511, 81061156, 26013199);
--Luego, gracias a el id de las personas dueñas de cada cuenta, se buscaran en people
SELECT * FROM people
WHERe id IN (686048, 948985, 514354, 458378, 395717, 396669, 467400, 449774, 438727);


--Ruth ID: 161, menciona que vio al sospechoso subirse a un coche frente a la "bakery"
SELECT * FROM bakery_security_logs
WHERE license_plate IN ('30G67EN', 'L93JTIZ', '8X428L0', '1106N58', 'QX4YZN3', '4328GD8', '322W7JE', '94KL13X', 'I449449');



--Revisemos los vuelos y pasajeros de cada vuelo en la fecha del dia siguiente
--Raymond menciona que escucho que el ladron tomaria un vuelo al dia siguiente
SELECT a.*
FROM flights AS a
INNER JOIN passengers AS s ON a.id = s.flight_id
INNER JOIN bank_accounts AS d ON s.passport_number = (SELECT passport_number FROM people WHERE id = d.person_id)
WHERE d.person_id IN (395717, 396669, 438727, 449774, 458378, 467400, 514354, 686048, 948985)
AND a.day = 29 AND a.month = 7 AND a.year = 2023;

--Esta consulta nos brinda todos los vuelos programados el 29/07/2023 con origin_airport_id = 8
--Gracia a Raymond, el vuelo del sospechoso podría ser el vuelo de ID 36, debido a que este menciona que el sospechoso tomaría el vuelo más temprano.
SELECT a.*, s1.full_name AS origin_airport, s2.full_name AS destination_airport
FROM flights AS a
INNER JOIN airports AS s1 ON a.origin_airport_id = s1.id
INNER JOIN airports AS s2 ON a.destination_airport_id = s2.id
WHERE a.id = 36;
--ID 36
--Aeropuerto origen "Fiftyville..."
--Aeropuerto destino "LaGuardia Airport"
--Fecha 29/07/2023
--Hora 8:20

--Ahora consultemos acerca de los pasajeros de este vuelo...
SELECT a.*
FROM passengers AS pas
INNER JOIN flights AS s ON pas.flight_id = s.id
INNER JOIN people AS a ON pas.passport_number = a.passport_number
WHERE s.id = 36;

--Verificamos denuevo las transacciones del dia del crimen
SELECT b.account_number, ba.person_id
FROM atm_transactions AS b
INNER JOIN bank_accounts AS ba ON b.account_number = ba.account_number
WHERE b.year = 2023 AND b.month = 7 AND b.day = 28 AND b.atm_location = 'Leggett Street';

--Y comparamos si el person_id coincide con el person_id de Bruce el cual es el principal sospechoso

SELECT a.*
FROM passengers AS pas
INNER JOIN flights AS s ON pas.flight_id = s.id
INNER JOIN people AS a ON pas.passport_number = a.passport_number
WHERE s.id = 36 AND a.id = (SELECT ba.person_id
                             FROM atm_transactions AS b
                             INNER JOIN bank_accounts AS ba ON b.account_number = ba.account_number
                             WHERE b.year = 2023 AND b.month = 7 AND b.day = 28 AND b.atm_location = 'Leggett Street');

