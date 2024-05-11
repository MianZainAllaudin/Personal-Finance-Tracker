CREATE TABLE [dbo].[Income_goal] (
    [Username]    VARCHAR (50) NOT NULL,
    [income_goal] BIGINT       NOT NULL,
    FOREIGN KEY ([Username]) REFERENCES [dbo].[Credentials] ([Username])
);

