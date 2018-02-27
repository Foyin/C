#include <stdio.h>
#include <string.h>

#define MAX_STR 32
#define MAX_VEHICLES 4
#define MAX_CUSTOMERS 6

//Foyin Ogbara 100900459

typedef struct {
	
	char make[MAX_STR];
	char model[MAX_STR];
	char colour[MAX_STR];
	int year;
	int mileage;

} VehicleType;

typedef struct {

	char firstName[MAX_STR];
	char lastName[MAX_STR];
	int numregistered;
	VehicleType ownedByCustomer[MAX_VEHICLES];


} CustomerType;

void print_vehicle(VehicleType *v) {

	printf("%s %s %s, %d, %dkm\n",
	      v->make, v->model, v->colour, v->year, v->mileage);
}

void print_customer(CustomerType *c) {

	printf("Name: %s %s, numregistered: %d\n",
	      c->firstName, c->lastName, c->numregistered);
	
	printf("Vehicles owned by customer:\n");
	for(int i; i < c->numregistered; i++){
	print_vehicle(&c->ownedByCustomer[i]);
	}
}

int add_vehicle(CustomerType *customer, VehicleType *vehicle) {
	
int r = -1;
	
	if(customer->numregistered <= MAX_VEHICLES){
	customer->ownedByCustomer[customer->numregistered] = *vehicle;
	customer->numregistered++;
	r = 0;	
	}
	else printf("Four vehicle limit");

	return r;
}

CustomerType create_customer(char* fname, char* lname) {

	CustomerType c;
	strcpy(c.firstName, fname);
	strcpy(c.lastName, lname);

	return c;
}

VehicleType create_vehicle(char* make, char* model, char* colour,
                            int year, int mileage) {
	VehicleType v;
	strcpy(v.make, make);
	strcpy(v.model, model);
	strcpy(v.colour, colour);
	v.year = year;
	v.mileage = mileage;

	return v;
}


int main() {

	CustomerType customers[MAX_CUSTOMERS];
	VehicleType vehicle[MAX_VEHICLES];
	
	vehicle[0] = create_vehicle("BMW", "M1", "Black", 2017, 30000);
	vehicle[1] = create_vehicle("Alfa romeo", "Disco volante", "Red", 2014, 40000);
	vehicle[2] = create_vehicle("Toyota", "Camry", "Grey", 2007, 80000);
	vehicle[3] = create_vehicle("Tesla", "Roadster", "Blue", 2018, 2000);
	
	customers[0] = create_customer("Olga", "Gurlukovich");
	customers[1] = create_customer("Kazushira", "Miller");
	customers[2] = create_customer("David", "Hayter");
	customers[3] = create_customer("Hamyuts", "Meseta");
	customers[4] = create_customer("Mattalast", "Ballory");


	add_vehicle(&customers[0], &vehicle[3]);
	print_customer(&customers[0]);

	printf("\n");

	add_vehicle(&customers[1], &vehicle[0]);
	add_vehicle(&customers[1], &vehicle[1]);
	print_customer(&customers[1]);


	printf("\n");

	add_vehicle(&customers[2], &vehicle[0]);
	add_vehicle(&customers[2], &vehicle[2]);
	add_vehicle(&customers[2], &vehicle[1]);
	print_customer(&customers[2]);

	printf("\n");

	add_vehicle(&customers[3], &vehicle[0]);
	add_vehicle(&customers[3], &vehicle[1]);
	add_vehicle(&customers[3], &vehicle[2]);
	add_vehicle(&customers[3], &vehicle[3]);
	print_customer(&customers[3]);

	printf("\n");

	add_vehicle(&customers[4], &vehicle[0]);
	print_customer(&customers[4]);

	
    return 0;
}


