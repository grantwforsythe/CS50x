-- Keep a log of any SQL queries you execute as you solve the mystery.
/*
    TODO: Find who these people spoke to 
    TODO: The THIEF is:
    TODO: The thief ESCAPED TO:
    TODO: The ACCOMPLICE is
*/

-- initially the schema was viewed to see the structure of the database

/*
    view the the initial report of the crime
    mentions three witnesses were interviewed who were present during the crime
    it stated the interviews were conducted the same day and each person mentioned the courthouse
*/
SELECT description FROM crime_scene_reports
WHERE year = 2020
AND month = 7
AND day = 28
AND street = 'Chamberlin Street';
/*
    Output:
    Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. 
    Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.
*/

/*
    wanted to the names of those interviewed and what was mentioned
    interviewes: Ruth, Eugene, Raymond
*/
SELECT name, transcript FROM interviews
WHERE year = 2020
AND month = 7
AND day = 28
AND transcript LIKE '%courthouse%';
/*
    Output:
    Ruth,   Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away. 
            If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
    Eugene, I don't know the thief's name, but it was someone I recognized. 
            Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
    Raymond, As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. 
            In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. 
            The thief then asked the person on the purchase the flight ticket.

    Takeaways:
        - thief left in a car from the courthouse parking lot (courthouse_security_logs)
        - the thief withdrew money from an ATM on Fifer Street earlier that morning (ATM_transactions & bank_accounts)
        - spoke with someone for less than a minute on the phone during the robbery (phone_calls)
        - planning on taking the earliest flight out of Fiftyville the next day (flights)
        - the person on the other end of the phone purchased the ticket (bank_accounts)
*/

-- .tables && .schema courthouse_security_logs 

-- don't know when the approximate time the crime happened
-- decided to check the phone logs next
SELECT hour, minute, activity, license_plate FROM courthouse_security_logs
WHERE year = 2020
AND month = 7
AND day = 28
AND hour > 12; -- the last condition was an assumption and was removed later

-- wanted to know who made a phone call that day for less than a minute
SELECT caller, receiver FROM phone_calls
WHERE year = 2020
AND month = 7
AND day = 28
AND duration < 60;
/*
    Output:
    caller          receiver      
--------------  --------------
(130) 555-0289  (996) 555-8899
(499) 555-9472  (892) 555-8872
(367) 555-5533  (375) 555-8161
(609) 555-5876  (389) 555-5198
(499) 555-9472  (717) 555-1342
(286) 555-6063  (676) 555-6554
(770) 555-1861  (725) 555-3243
(031) 555-6622  (910) 555-3251
(826) 555-1652  (066) 555-9701
(338) 555-6650  (704) 555-2131
*/

/*
    - wanted to follow up with the ATM transcation
    - the name of people and their phone number who made withdrew money from that ATM that day
    - my next query will be to see who made calls the day of the robbery for less than a minute
    - the people mentioned below are all people of interest now 
    - want to find the outbound caller
*/
SELECT people.name, people.phone_number FROM people
INNER JOIN
    bank_accounts ON people.id = bank_accounts.person_id
WHERE bank_accounts.account_number IN (
    SELECT account_number FROM ATM_transactions 
    WHERE year = 2020
    AND month = 7
    AND day = 28
    AND atm_location = 'Fifer Street'
    AND transaction_type = 'withdraw'
);
/*
    Output:
    name        phone_number  
----------  --------------
Ernest      (367) 555-5533
Russell     (770) 555-1861
Roy         (122) 555-4581
Bobby       (826) 555-1652
Elizabeth   (829) 555-5269
Danielle    (389) 555-5198
Madison     (286) 555-6063
Victoria    (338) 555-6650
*/

/*
    - aggergating our findings, we can form a larger query to narrow down the potential suspects
    - we know that the thief made an ATM withdrawl on Fifer Street
    - we also know that the thief made a call for less than a minute during the robbery
    - and that the robbery left the scene in a automobile
*/
SELECT name FROM people
WHERE phone_number IN (
    -- phone call that lasted less than a minute that day
    SELECT caller FROM phone_calls
    WHERE year = 2020
    AND month = 7
    AND day = 28
    AND duration < 60 
    INTERSECT
    -- withdrew money from an ATM on Fifer Street that day
    SELECT people.phone_number FROM people
    INNER JOIN
        bank_accounts ON people.id = bank_accounts.person_id
    WHERE bank_accounts.account_number IN (
        SELECT account_number FROM ATM_transactions 
        WHERE year = 2020
        AND month = 7
        AND day = 28
        AND atm_location = 'Fifer Street'
        AND transaction_type = 'withdraw'
    )
)
-- has the license plate of a car that left the courthouse that day
AND license_plate IN (
    SELECT license_plate FROM courthouse_security_logs
    WHERE year = 2020
    AND month = 7
    AND day = 28
    AND activity = 'exit'
);
/*
    Output:
    name
----------
Madison
Russell
Ernest
*/

-- the flights out of Fiftyville the day after the robbery
SELECT destination_airport_id, hour, minute FROM flights
WHERE origin_airport_id = (
    -- originport will be Fiftyville, "First flight out of Fiftyville"
    SELECT id FROM airports
    WHERE city = 'Fiftyville'
)
AND year = 2020
AND month = 7
AND day = 29;
/*
    Output:
destination_airport_id  hour        minute    
----------------------  ----------  ----------
6                       16          0
11                      12          15        
4                       8           20        
1                       9           30
9                       15          20
*/

-- look at all the passengers on these flights and compare them to the three suspects
SELECT * FROM flights 
INNER JOIN
    passengers ON flights.id = passengers.flight_id
WHERE origin_airport_id = (
    -- originport will be Fiftyville, "First flight out of Fiftyville"
    SELECT id FROM airports
    WHERE city = 'Fiftyville'
)
AND year = 2020
AND month = 7
AND day = 29
AND passengers.passport_number IN (
    SELECT passport_number FROM people
    WHERE name IN ('Madison', 'Russell', 'Ernest')
); 
/*
    Output:
    id          origin_airport_id  destination_airport_id  year        month       day         hour        minute      flight_id   passport_number  seat      
----------  -----------------  ----------------------  ----------  ----------  ----------  ----------  ----------  ----------  ---------------  ----------
18          8                  6                       2020        7           29          16          0           18          3592750733       4C
36          8                  4                       2020        7           29          8           20          36          5773159633       4A
36          8                  4                       2020        7           29          8           20          36          1988161715       6D
*/

/*
    - all of the potential suspects were on a flight the day after the robbery
    - two of the suspects were on the same flight which seems suspect
*/
-- destination_airport_id(6): Boston
-- destination_airport_id(4): London

/*
name        passport_number
----------  ---------------
Madison     1988161715 --> London
Russell     3592750733 --> Boston
Ernest      5773159633 --> London
*/


-- to aggregate what we got so far, the thief is either Ernest or Madison
-- we have to find out who each other phoned
SELECT * FROM flights
INNER JOIN
    passengers ON flights.id = passengers.flight_id
INNER JOIN
    people ON passengers.passport_number = people.passport_number
WHERE flights.origin_airport_id = (
    SELECT id FROM airports
    WHERE city = 'Fiftyville'
)
AND flights.year = 2020
AND flights.month = 7
AND flights.day = 29
AND passengers.passport_number IN (
    SELECT passport_number FROM people
    WHERE name IN (
        SELECT name FROM people
        WHERE phone_number IN (
            -- phone call that lasted less than a minute that day
            SELECT caller FROM phone_calls
            WHERE year = 2020
            AND month = 7
            AND day = 28
            AND duration < 60 
            INTERSECT
            -- withdrew money from an ATM on Fifer Street that day
            SELECT people.phone_number FROM people
            INNER JOIN
                bank_accounts ON people.id = bank_accounts.person_id
            WHERE bank_accounts.account_number IN (
                SELECT account_number FROM ATM_transactions 
                WHERE year = 2020
                AND month = 7
                AND day = 28
                AND atm_location = 'Fifer Street'
                AND transaction_type = 'withdraw'
            )
        )
        -- has the license plate of a car that left the courthouse that day
        AND license_plate IN (
            SELECT license_plate FROM courthouse_security_logs
            WHERE year = 2020
            AND month = 7
            AND day = 28
            AND activity = 'exit'
        )
    )
);

-- we know there will robbery and their partner will be on the flight

-- these were the two numbers Ernest and Madison called respectively
SELECT name, phone_number FROM people
WHERE phone_number = '(375) 555-8161' OR phone_number = '(676) 555-6554';

-- now just need to if these guys were on the plan with the thief
-- who ever is, the person who phoned them must be the thief
SELECT people.name FROM flights
INNER JOIN
    passengers ON flight_id = passengers.flight_id
INNER JOIN
    people ON passengers.passport_number = people.passport_number
WHERE flights.id = 36
AND people.passport_number = (
    SELECT passport_number FROM people
    WHERE phone_number = '(375) 555-8161'
);
/*
    Output:
    - since this query doesn't return anything, Ernest can not be the thief because the reciever purchased the ticket
    - therefore, Madison must be the thief because she phoned and James is the partner
*/--I made the wrong assumption. The partner didn't take the plane with the thief. Therefore, the correct answer is Ernest (thief) and Berthold (partner) went to London after stealing the duck
