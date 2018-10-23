from astroquery.jplhorizons import Horizons
# from astroquery.jplhorizons import conf
# conf.horizons_server = 'https://ssd.jpl.nasa.gov/horizons_batch.cgi'
# from keyring.util.escape import escape as escape_for_ini


"""The script retrieves the initial position and velocity of all objects int
planet_id and prints them to files for position and velocity respectivly"""
planet_id = ['10', '199', '299', '399',
             '499', '599', '699', '799', '899', '999']
with open('pos_values.txt', 'w+') as f:
    for planet in planet_id:

        obj = Horizons(id=planet, id_type='majorbody', epochs={
                       'start': '2018-10-22', 'stop': '2018-11-1', 'step': '1d'})
        vec = obj.vectors()

        f.write(str(vec['x'][0]))
        f.write(' ')
        f.write(str(vec['y'][0]))
        f.write(' ')
        f.write(str(vec['z'][0]))
        f.write("\n")


f.close()

with open('vel_values.txt', 'w+') as f:
    for planet in planet_id:

        obj = Horizons(id=planet, id_type='majorbody', epochs={
                       'start': '2018-10-22', 'stop': '2018-11-1', 'step': '1d'})
        vec = obj.vectors()

        f.write(str(vec['vx'][0]))
        f.write(' ')
        f.write(str(vec['vy'][0]))
        f.write(' ')
        f.write(str(vec['vz'][0]))
        f.write("\n")


f.close()
