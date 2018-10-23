from astroquery.jplhorizons import Horizons
# from astroquery.jplhorizons import conf
# conf.horizons_server = 'https://ssd.jpl.nasa.gov/horizons_batch.cgi'
# from keyring.util.escape import escape as escape_for_ini

planet_id = ['10', '199', '299', '399', '499', '599', '699', '799', '899']
with open('init_values.txt', 'w+') as f:
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
        f.write(str(vec['vx'][0] * 365.))
        f.write(' ')
        f.write(str(vec['vy'][0] * 365.))
        f.write(' ')
        f.write(str(vec['vz'][0] * 365.))
        f.write("\n")


f.close()
# vec['x'][0]
# vec['y'][0]
# vec['z'][0]


# print(Earth_x)
# print(Earth_y)
