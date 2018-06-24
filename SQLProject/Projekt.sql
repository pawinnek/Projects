Create table Kontrahenci
(
    Id_Kontrahenta number(4) constraint kontrahenci_pk Primary Key,
    Nazwa_Firmy varchar(100) ,
    NIP number(10),
    Pesel number(11),
    Imie varchar(20),
    Nazwisko varchar(40),
    Adres varchar(30)
    

)
drop table transakcje CASCADE constraints ;
Create table Towary
(
    Id_Towaru varchar(4) constraint  towary_pk Primary Key,
    EAN13 number(13),
    EAN8 number(8),
    code25i number(6) not null,
    miara number(6),
    typ_miary varchar(4)
)

Create table Wyroby_Gotowe
(
    Id_Wyrobu varchar(4) constraint Wyroby_pk Primary Key,
    EAN13 number(13),
    EAN8 number(8),
    Code25i number(6) not null,
    miara number(6),
    typ_miary varchar(4)  
)

Create table Materialy
(
    Id_Materialu varchar(4) constraint materialy_pk Primary Key,
    EAN13 number(13),
    EAN8 number(8),
    Code25i number(6) not null,
    miara number(6),
    typ_miary varchar(4)   
)

create table WZ
(
    Nr_dokumentu varchar(26) constraint wz_pk Primary Key,
    Foreign key(id_odbiorcy) references kontrahenci(id_kontrahenta),
    
)

create table Dokumenty
(
    Nr_dokumentu varchar(26) constraint Dokumenty_pk Primary Key,
)
create table transakcje
(
    Foreign Key(Nr_dokumentu) references Dokumenty(Nr_Dokumentu) 
)