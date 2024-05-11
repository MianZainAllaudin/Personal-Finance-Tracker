CREATE TABLE [dbo].[Transactions] (
    [Username]    VARCHAR (50)  NOT NULL,
    [ID]          BIGINT        IDENTITY (1, 1) NOT NULL,
    [Description] VARCHAR (255) NOT NULL,
    [Category]    VARCHAR (50)  NOT NULL,
    [Type]        VARCHAR (50)  NOT NULL,
    [date]        DATE          NOT NULL,
    [Amount]      BIGINT        NOT NULL,
    PRIMARY KEY CLUSTERED ([ID] ASC),
    FOREIGN KEY ([Username]) REFERENCES [dbo].[Credentials] ([Username])
);

