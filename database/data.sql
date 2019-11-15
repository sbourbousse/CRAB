insert into type_borne values ("AAA",6,230,100),("BBB",4,170,89);



load data local infile './station.csv' into table station
	CHARACTER SET utf8
	fields terminated by ';'
	lines terminated by '\n';

load data local infile './borne.csv' into table borne
	CHARACTER SET utf8
	fields terminated by ';'
	lines terminated by '\n';

load data local infile './technicien.csv' into table technicien
	CHARACTER SET utf8
	fields terminated by ';'
	lines terminated by '\n';

load data local infile './possede.csv' into table possede
	CHARACTER SET utf8
	fields terminated by ';'
	lines terminated by '\n';



