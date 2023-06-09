----
# Country Lookup Example
This FHE toolkit example demonstrates a privacy preserving search against an encrypted database. The database is a key value store prepopulated with the english names of countries and their capital cities. Selecting the country will use HElib to perform a search of the matching capital. `BGV` refers to the encryption scheme used in the demo, more information on the schemes is available [here](https://en.wikipedia.org/wiki/Homomorphic_encryption).

## Relation to a real use case
Privacy preserving search is a common scenario to demonstrate the benefits of homomorphic encryption. Being able to perform a query while preserving the privacy and secrecy of the parameters of the query has many applications across various industry segments spanning from genomics to finance. This example uses a simple and easy to follow algorithm that demonstrates how one can use homomorphic encryption based techniques to generate a mask to retrieve data from a key-value pair database. It uses a dataset that is understandable for users across all industries and expertise levels. 

With respect to realism of data, the dataset takes into account all countries. In a real use case, this could be information on customers or financial records for example. This is an educational example so a small dataset was needed to ensure timely responses and that it was relevant for all users.

## Build
Change directory to the example's home directory, then execute:

    cmake .
    make

## Run and Validate
Run the country capital lookup over the encrypted dataset:

    ./BGV_world_country_db_lookup

Type in a Country name. For example Sweden, Germany, Czech Republic. For countries in the United Kingdom, use one of: England, Scotland, Wales and Northern Ireland.

Please note: there is no fuzzy matching, the spelling of the country name has to be exact.

## Acknowledgement
This country lookup example is derived from the BGV database demo code originally written by Jack Crawford for a lunch and learn session at IBM Research (Hursley) in 2019. The original demo code ships with HElib and can be found [here](https://github.com/IBM-HElib/HElib/tree/master/examples).

## Appendix - Full List of Countries
To view the options available for this demo, see the [dataset](countries_dataset.csv).
