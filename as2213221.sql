/*
Created: 22.11.2023
Modified: 22.11.2023
Model: Logical model
Database: MS SQL Server 2012
*/


-- Create tables section -------------------------------------------------

-- Table Поставщик

CREATE TABLE [Поставщик]
(
 [ID поставщика] Bigint NOT NULL,
 [цена товара] Money NULL,
 [кол-во товара] Bigint NULL
)
go

-- Add keys for table Поставщик

ALTER TABLE [Поставщик] ADD CONSTRAINT [Unique_Identifier1] PRIMARY KEY ([ID поставщика])
go

-- Table Товар

CREATE TABLE [Товар]
(
 [ID товара] Bigint NOT NULL,
 [Кол-во товара] Bigint NULL,
 [Наименование товара] Char(256) NULL
)
go

-- Add keys for table Товар

ALTER TABLE [Товар] ADD CONSTRAINT [Unique_Identifier2] PRIMARY KEY ([ID товара])
go

-- Table Куплено

CREATE TABLE [Куплено]
(
 [ID покупки] Bigint NOT NULL,
 [Кол-во товара] Bigint NULL,
 [цена товара] Money NULL,
 [ID чека закупки] Bigint NOT NULL,
 [ID поставщика] Bigint NOT NULL,
 [ID товара] Bigint NOT NULL
)
go

-- Add keys for table Куплено

ALTER TABLE [Куплено] ADD CONSTRAINT [Unique_Identifier3] PRIMARY KEY ([ID покупки],[ID чека закупки],[ID поставщика],[ID товара])
go

-- Table Продано

CREATE TABLE [Продано]
(
 [ID продажи] Bigint NOT NULL,
 [Кол-во товара] Bigint NULL,
 [Стоимость] Money NULL,
 [ID товара] Bigint NOT NULL
)
go

-- Add keys for table Продано

ALTER TABLE [Продано] ADD CONSTRAINT [Unique_Identifier4] PRIMARY KEY ([ID продажи],[ID товара])
go

-- Table Чек покупки

CREATE TABLE [Чек покупки]
(
 [ID чека закупки] Bigint NOT NULL,
 [кол-во товара] Bigint NULL,
 [цена товара] Bigint NULL,
 [ID поставщика] Bigint NOT NULL
)
go

-- Add keys for table Чек покупки

ALTER TABLE [Чек покупки] ADD CONSTRAINT [Unique_Identifier5] PRIMARY KEY ([ID чека закупки],[ID поставщика])
go

-- Table Чек продажи

CREATE TABLE [Чек продажи]
(
 [ID чека] Bigint NOT NULL,
 [Кол-во товара] Bigint NULL,
 [Стоимость] Money NULL,
 [Доход] Money NULL,
 [ID продажи] Bigint NOT NULL,
 [ID товара] Bigint NOT NULL,
 [ID покупателя] Bigint NOT NULL
)
go

-- Add keys for table Чек продажи

ALTER TABLE [Чек продажи] ADD CONSTRAINT [Unique_Identifier6] PRIMARY KEY ([ID чека],[ID продажи],[ID товара],[ID покупателя])
go

-- Table Покупатель

CREATE TABLE [Покупатель]
(
 [ID покупателя] Bigint NOT NULL,
 [Цена товара] Money NULL,
 [Кол-во товара] Bigint NULL
)
go

-- Add keys for table Покупатель

ALTER TABLE [Покупатель] ADD CONSTRAINT [Unique_Identifier7] PRIMARY KEY ([ID покупателя])
go

-- Create foreign keys (relationships) section ------------------------------------------------- 


ALTER TABLE [Чек покупки] ADD CONSTRAINT [Relationship1] FOREIGN KEY ([ID поставщика]) REFERENCES [Поставщик] ([ID поставщика]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [Куплено] ADD CONSTRAINT [Relationship2] FOREIGN KEY ([ID чека закупки], [ID поставщика]) REFERENCES [Чек покупки] ([ID чека закупки], [ID поставщика]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [Куплено] ADD CONSTRAINT [Relationship3] FOREIGN KEY ([ID товара]) REFERENCES [Товар] ([ID товара]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [Продано] ADD CONSTRAINT [Relationship4] FOREIGN KEY ([ID товара]) REFERENCES [Товар] ([ID товара]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [Чек продажи] ADD CONSTRAINT [Relationship5] FOREIGN KEY ([ID продажи], [ID товара]) REFERENCES [Продано] ([ID продажи], [ID товара]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [Чек продажи] ADD CONSTRAINT [Relationship6] FOREIGN KEY ([ID покупателя]) REFERENCES [Покупатель] ([ID покупателя]) ON UPDATE NO ACTION ON DELETE NO ACTION
go




