--
-- File generated with SQLiteStudio v3.2.1 on ๓า อมา 20 22:08:51 2019
--
-- Text encoding used: KOI8-R
--
PRAGMA foreign_keys = off;
BEGIN TRANSACTION;

-- Table: authors
CREATE TABLE authors (
    id        INTEGER PRIMARY KEY,
    name      VARCHAR,
    birthdate DATE
);

INSERT INTO authors (
                        id,
                        name,
                        birthdate
                    )
                    VALUES (
                        1,
                        'Isaac Asimov',
                        '1920-02-01'
                    );

INSERT INTO authors (
                        id,
                        name,
                        birthdate
                    )
                    VALUES (
                        2,
                        'Graham Greene',
                        '1904-10-02'
                    );

INSERT INTO authors (
                        id,
                        name,
                        birthdate
                    )
                    VALUES (
                        3,
                        'Terry Pratchett',
                        '1948-04-28'
                    );

INSERT INTO authors (
                        id,
                        name,
                        birthdate
                    )
                    VALUES (
                        4,
                        'Agatha Christie',
                        '1890-09-15'
                    );

INSERT INTO authors (
                        id,
                        name,
                        birthdate
                    )
                    VALUES (
                        5,
                        'Ray Bradbury',
                        '1920-08-22'
                    );

INSERT INTO authors (
                        id,
                        name,
                        birthdate
                    )
                    VALUES (
                        6,
                        'Stanis?aw Lem',
                        '1921-09-13'
                    );

INSERT INTO authors (
                        id,
                        name,
                        birthdate
                    )
                    VALUES (
                        7,
                        'Harry Harrison',
                        '1925-03-12'
                    );

INSERT INTO authors (
                        id,
                        name,
                        birthdate
                    )
                    VALUES (
                        8,
                        'Richard Dawkins',
                        '1941-03-26'
                    );


-- Table: books
CREATE TABLE books (
    id     INTEGER PRIMARY KEY,
    title  VARCHAR,
    author INTEGER,
    genre  INTEGER,
    year   INTEGER,
    rating INTEGER
);

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      1,
                      'Foundation',
                      1,
                      1,
                      1951,
                      3
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      2,
                      'Foundation and Empire',
                      1,
                      1,
                      1952,
                      4
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      3,
                      'Second Foundation',
                      1,
                      1,
                      1953,
                      3
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      4,
                      'Foundation''s Edge',
                      1,
                      1,
                      1982,
                      3
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      5,
                      'Foundation and Earth',
                      1,
                      1,
                      1986,
                      4
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      6,
                      'Prelude to Foundation',
                      1,
                      1,
                      1988,
                      3
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      7,
                      'Forward the Foundation',
                      1,
                      1,
                      1993,
                      3
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      8,
                      'The Power and the Glory',
                      2,
                      2,
                      1940,
                      4
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      9,
                      'The Third Man',
                      2,
                      2,
                      1950,
                      5
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      10,
                      'Our Man in Havana',
                      2,
                      2,
                      1958,
                      4
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      11,
                      'Guards! Guards!',
                      3,
                      3,
                      1989,
                      3
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      12,
                      'Night Watch',
                      3,
                      3,
                      2002,
                      3
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      13,
                      'Going Postal',
                      3,
                      3,
                      2004,
                      3
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      14,
                      'The Murder at the Vicarage',
                      4,
                      4,
                      1930,
                      2
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      15,
                      'Murder on the Orient Express',
                      4,
                      4,
                      1934,
                      2
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      16,
                      'The Murder of Roger Ackroyd',
                      4,
                      4,
                      1926,
                      2
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      17,
                      'Death on the Nile',
                      4,
                      4,
                      1937,
                      2
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      18,
                      'Fahrenheit 451',
                      5,
                      1,
                      1953,
                      3
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      19,
                      'Dandelion Wine',
                      5,
                      1,
                      1957,
                      3
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      20,
                      'The Martian Chronicles',
                      5,
                      1,
                      1950,
                      3
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      21,
                      'The Illustrated Man',
                      5,
                      1,
                      1951,
                      3
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      22,
                      'The Astronauts',
                      6,
                      1,
                      1951,
                      3
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      23,
                      'The Magellanic Cloud',
                      6,
                      1,
                      1955,
                      3
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      24,
                      'The Star Diaries',
                      6,
                      1,
                      1959,
                      2
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      25,
                      'Summa Technologiae',
                      6,
                      1,
                      1964,
                      3
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      26,
                      'The Futurological Congress',
                      6,
                      1,
                      1971,
                      4
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      27,
                      'The Stainless Steel Rat',
                      7,
                      1,
                      1961,
                      4
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      28,
                      'Planet of the Damned',
                      7,
                      1,
                      1962,
                      3
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      29,
                      'Deathworld',
                      7,
                      1,
                      1960,
                      3
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      30,
                      'Captive Universe',
                      7,
                      1,
                      1969,
                      2
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      31,
                      'The Selfish Gene',
                      8,
                      5,
                      1976,
                      4
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      32,
                      'The Extended Phenotype',
                      8,
                      5,
                      1982,
                      4
                  );

INSERT INTO books (
                      id,
                      title,
                      author,
                      genre,
                      year,
                      rating
                  )
                  VALUES (
                      33,
                      'The Blind Watchmaker',
                      8,
                      5,
                      1986,
                      4
                  );


-- Table: genres
CREATE TABLE genres (
    id   INTEGER PRIMARY KEY,
    name VARCHAR
);

INSERT INTO genres (
                       id,
                       name
                   )
                   VALUES (
                       1,
                       'Science Fiction'
                   );

INSERT INTO genres (
                       id,
                       name
                   )
                   VALUES (
                       2,
                       'Fiction'
                   );

INSERT INTO genres (
                       id,
                       name
                   )
                   VALUES (
                       3,
                       'Fantasy'
                   );

INSERT INTO genres (
                       id,
                       name
                   )
                   VALUES (
                       4,
                       'Detective Fiction'
                   );

INSERT INTO genres (
                       id,
                       name
                   )
                   VALUES (
                       5,
                       'Science'
                   );


COMMIT TRANSACTION;
PRAGMA foreign_keys = on;
