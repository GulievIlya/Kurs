/*
Created: 22.11.2023
Modified: 22.11.2023
Model: Logical model
Database: MS SQL Server 2012
*/


-- Create tables section -------------------------------------------------

-- Table ���������

CREATE TABLE [���������]
(
 [ID ����������] Bigint NOT NULL,
 [���� ������] Money NULL,
 [���-�� ������] Bigint NULL
)
go

-- Add keys for table ���������

ALTER TABLE [���������] ADD CONSTRAINT [Unique_Identifier1] PRIMARY KEY ([ID ����������])
go

-- Table �����

CREATE TABLE [�����]
(
 [ID ������] Bigint NOT NULL,
 [���-�� ������] Bigint NULL,
 [������������ ������] Char(256) NULL
)
go

-- Add keys for table �����

ALTER TABLE [�����] ADD CONSTRAINT [Unique_Identifier2] PRIMARY KEY ([ID ������])
go

-- Table �������

CREATE TABLE [�������]
(
 [ID �������] Bigint NOT NULL,
 [���-�� ������] Bigint NULL,
 [���� ������] Money NULL,
 [ID ���� �������] Bigint NOT NULL,
 [ID ����������] Bigint NOT NULL,
 [ID ������] Bigint NOT NULL
)
go

-- Add keys for table �������

ALTER TABLE [�������] ADD CONSTRAINT [Unique_Identifier3] PRIMARY KEY ([ID �������],[ID ���� �������],[ID ����������],[ID ������])
go

-- Table �������

CREATE TABLE [�������]
(
 [ID �������] Bigint NOT NULL,
 [���-�� ������] Bigint NULL,
 [���������] Money NULL,
 [ID ������] Bigint NOT NULL
)
go

-- Add keys for table �������

ALTER TABLE [�������] ADD CONSTRAINT [Unique_Identifier4] PRIMARY KEY ([ID �������],[ID ������])
go

-- Table ��� �������

CREATE TABLE [��� �������]
(
 [ID ���� �������] Bigint NOT NULL,
 [���-�� ������] Bigint NULL,
 [���� ������] Bigint NULL,
 [ID ����������] Bigint NOT NULL
)
go

-- Add keys for table ��� �������

ALTER TABLE [��� �������] ADD CONSTRAINT [Unique_Identifier5] PRIMARY KEY ([ID ���� �������],[ID ����������])
go

-- Table ��� �������

CREATE TABLE [��� �������]
(
 [ID ����] Bigint NOT NULL,
 [���-�� ������] Bigint NULL,
 [���������] Money NULL,
 [�����] Money NULL,
 [ID �������] Bigint NOT NULL,
 [ID ������] Bigint NOT NULL,
 [ID ����������] Bigint NOT NULL
)
go

-- Add keys for table ��� �������

ALTER TABLE [��� �������] ADD CONSTRAINT [Unique_Identifier6] PRIMARY KEY ([ID ����],[ID �������],[ID ������],[ID ����������])
go

-- Table ����������

CREATE TABLE [����������]
(
 [ID ����������] Bigint NOT NULL,
 [���� ������] Money NULL,
 [���-�� ������] Bigint NULL
)
go

-- Add keys for table ����������

ALTER TABLE [����������] ADD CONSTRAINT [Unique_Identifier7] PRIMARY KEY ([ID ����������])
go

-- Create foreign keys (relationships) section ------------------------------------------------- 


ALTER TABLE [��� �������] ADD CONSTRAINT [Relationship1] FOREIGN KEY ([ID ����������]) REFERENCES [���������] ([ID ����������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [�������] ADD CONSTRAINT [Relationship2] FOREIGN KEY ([ID ���� �������], [ID ����������]) REFERENCES [��� �������] ([ID ���� �������], [ID ����������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [�������] ADD CONSTRAINT [Relationship3] FOREIGN KEY ([ID ������]) REFERENCES [�����] ([ID ������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [�������] ADD CONSTRAINT [Relationship4] FOREIGN KEY ([ID ������]) REFERENCES [�����] ([ID ������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [��� �������] ADD CONSTRAINT [Relationship5] FOREIGN KEY ([ID �������], [ID ������]) REFERENCES [�������] ([ID �������], [ID ������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go



ALTER TABLE [��� �������] ADD CONSTRAINT [Relationship6] FOREIGN KEY ([ID ����������]) REFERENCES [����������] ([ID ����������]) ON UPDATE NO ACTION ON DELETE NO ACTION
go




