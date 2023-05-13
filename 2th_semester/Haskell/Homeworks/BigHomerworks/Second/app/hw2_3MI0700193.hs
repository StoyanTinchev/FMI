import Data.List (nub)

-- #####################################Task 1############################################
longestColorMovieLength :: MovieDB -> Int
longestColorMovieLength (movieList, _, _) = foldl maxColorMovieLength (-1) movieList
  where
    maxColorMovieLength acc (_, _, length, color, _)
      | color == 'Y' && length > acc = length
      | otherwise = acc

getNameLengthColor :: MovieDB -> ((Char -> Bool), (Int -> Bool)) -> [(Title, Length)]
getNameLengthColor (moviesList, studiosList, producersList) (colorPredicate, lengthPredicate) =
  [ (title, length)
    | (title, _, length, color, _) <- moviesList,
      colorPredicate color,
      length /= longestColorMovieLength (moviesList, studiosList, producersList),
      lengthPredicate length,
      length >= 0
  ]

-- #######################################################################################

-- #####################################Task 2############################################
-- Намира името на продуцент по даден ID в списък с продуценти
getProducerName :: ProducerID -> [MovieExec] -> Name
getProducerName producerId execs =
  head [name | (name, id, _) <- execs, id == producerId]

-- Генерира списък с годините, в които дадено студио е произвело филми
getStudioMovieYears :: StudioName -> [Movie] -> [Year]
getStudioMovieYears studioName movies =
  [year | (_, year, _, _, movieStudio) <- movies, movieStudio == studioName]

-- Връща истинска стойност, ако дадено студио е произвело филми само в една година
-- и тази година е в списъка с предоставените години
isSingleYearStudio :: StudioName -> [Movie] -> [Year] -> Bool
isSingleYearStudio studioName movies selectedYears =
  null studioYears || (length uniqueStudioYears == 1 && head uniqueStudioYears `elem` selectedYears)
  where
    studioYears = getStudioMovieYears studioName movies
    uniqueStudioYears = nub studioYears

getStudios :: MovieDB -> ([Year] -> [(StudioName, Name)])
getStudios (movieList, studioList, execList) =
  \selectedYears ->
    [ (studioName, getProducerName producerId execList)
      | (studioName, producerId) <- studioList,
        isSingleYearStudio studioName movieList selectedYears
    ]

-- #######################################################################################

main :: IO ()
main = do
  print $
    getNameLengthColor db ((== 'Y'), (> 106))
      == [ ("Pretty Woman", 119),
           ("The Man Who Wasn't There", 116),
           ("Logan's run", 120),
           ("Empire Strikes Back", 111),
           ("Star Trek", 132),
           ("Star Trek: Nemesis", 116)
         ]
  print $ getNameLengthColor db ((== 'Y'), (> 237)) == []
  print $ getNameLengthColor db ((== 'Y'), (> 238)) == []
  print $ getNameLengthColor db ((== 'N'), (< 133)) == [("Terms of Endearment", 132)]
  print $ getNameLengthColor db ((== 'N'), (< 300)) == [("Terms of Endearment", 132)]

  print $
    (getStudios db) [2001]
      == [ ("USA Entertainm.", "Stephen Spielberg"),
           ("Buzzfeed Entertainm.", "Christian Baesler")
         ]
  print $
    (getStudios db) [2002]
      == [ ("Buzzfeed Entertainm.", "Christian Baesler")
         ]
  print $
    (getStudios db) [1990]
      == [ ("Disney", "Merv Griffin"),
           ("Buzzfeed Entertainm.", "Christian Baesler")
         ]
  print $
    (getStudios db) [1990, 2001, 1976]
      == [ ("Disney", "Merv Griffin"),
           ("USA Entertainm.", "Stephen Spielberg"),
           ("Buzzfeed Entertainm.", "Christian Baesler")
         ]
  print $ (getStudios db) [1979, 2002] == [("Buzzfeed Entertainm.", "Christian Baesler")]

type Title = String

type Year = Int

type Length = Int

type InColor = Char

type StudioName = String

type Name = String

type ProducerID = Int

type Networth = Integer

type Movie = (Title, Year, Length, InColor, StudioName)

type Studio = (Name, ProducerID)

type MovieExec = (Name, ProducerID, Networth)

type MovieDB = ([Movie], [Studio], [MovieExec])

studios :: [Studio]
studios =
  [ ("Disney", 199),
    ("USA Entertainm.", 222),
    ("Fox", 333),
    ("Paramount", 123),
    ("MGM", 555),
    ("Buzzfeed Entertainm.", 42)
  ]

movieExecs :: [MovieExec]
movieExecs =
  [ ("George Lucas", 555, 200000000),
    ("Ted Turner", 333, 125000000),
    ("Stephen Spielberg", 222, 100000000),
    ("Merv Griffin", 199, 112000000),
    ("Calvin Coolidge", 123, 20000000),
    ("Christian Baesler", 42, 420000)
  ]

movies :: [Movie]
movies =
  [ ("Pretty Woman", 1990, 119, 'Y', "Disney"),
    ("The Man Who Wasn't There", 2001, 116, 'Y', "USA Entertainm."),
    ("Logan's run", 1976, 120, 'Y', "Fox"),
    ("Star Wars", 1977, -1, 'N', "Fox"),
    ("Star Wars 2", 1977, 238, 'N', "Fox"),
    ("Empire Strikes Back", 1980, 111, 'Y', "Fox"),
    ("Star Trek", 1979, 132, 'Y', "Paramount"),
    ("Star Trek: Nemesis", 2002, 116, 'Y', "Paramount"),
    ("Terms of Endearment", 1983, 132, 'N', "MGM"),
    ("The Usual Suspects", 1995, 106, 'Y', "MGM"),
    ("Gone With the Wind", 1938, 238, 'Y', "MGM"),
    ("Gone With the Wind 2", 1938, 238, 'Y', "MGM"),
    ("The Fellowship of the Ring", 2001, -1, 'Y', "USA Entertainm.")
  ]

db :: MovieDB
db = (movies, studios, movieExecs)
