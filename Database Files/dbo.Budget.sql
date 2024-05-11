CREATE TABLE [dbo].[Budget] (
    [Username] VARCHAR (50) NULL,
    [Category] VARCHAR (50) NOT NULL,
    [Budget]   BIGINT       NOT NULL,
    FOREIGN KEY ([Username]) REFERENCES [dbo].[Credentials] ([Username])
);

