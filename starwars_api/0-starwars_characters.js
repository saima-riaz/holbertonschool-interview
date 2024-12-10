#!/usr/bin/env node

const axios = require('axios');  // Use axios instead of request

const movieId = process.argv[2];  // Get the Movie ID from the command line arguments

// Check if movieId is provided
if (!movieId) {
  console.log('Please provide a movie ID as a positional argument.');
  process.exit(1);
}

const url = `https://swapi-api.alx-tools.com/api/films/${movieId}/`;  // Star Wars API endpoint for the movie

// Make a request to the API to fetch movie details
axios.get(url)
  .then((response) => {
    const movieData = response.data;
    const characters = movieData.characters;

    // Iterate over the character URLs and fetch their names
    characters.forEach((characterUrl) => {
      axios.get(characterUrl)
        .then((response) => {
          console.log(response.data.name);  // Print the character's name
        })
        .catch((error) => {
          console.error('Error fetching character data:', error);
        });
    });
  })
  .catch((error) => {
    console.error('Error fetching movie data:', error);
  });
