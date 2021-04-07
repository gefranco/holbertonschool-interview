#!/usr/bin/node

const request = require('request');
const film = process.argv[2];
request('https://swapi-api.hbtn.io/api/films/' + film + '/', function (error, response, body) {
  if (response && response.statusCode !== 200) {
    return;
  }
  if (error) {
    return;
  }
  const json = JSON.parse(body);

  const characters = json.characters;

  for (let i = 0; i < characters.length; i++) {
    request(characters[i], function (error, response, body) {
      if (error) {
        return;
      }
      const jsonCharacter = JSON.parse(body);
      console.log(jsonCharacter.name);
    });
  }
});
