SELECT AVG(energy) FROm songs WHERE artist_id = (SELECT id FROM artists WHERE name = 'Drake');
select songs.name, energy, artists.name FROm songs
join artists on artists.id = songs.artist_id WHERE artists.name = 'Drake';

