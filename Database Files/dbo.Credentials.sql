CREATE TABLE [dbo].[Credentials] (
    [Username] VARCHAR (50)  NOT NULL,
    [Passkey]  VARCHAR (255) NOT NULL,
    [Income]   BIGINT        NULL,
    [Balance]  BIGINT        NULL,
    PRIMARY KEY CLUSTERED ([Username] ASC)
);

