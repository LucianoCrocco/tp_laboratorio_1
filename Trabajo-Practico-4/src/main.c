/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


int main(void)
{
	setbuf(stdout,NULL);

	//startTesting(1);  // ll_newLinkedList -> BIEN
	//startTesting(2);  // ll_len -> BIEN
	//startTesting(3);  // getNode - test_getNode -> BIEN
	//startTesting(4);  // addNode - test_addNode -> BIEN -> error del test
	//startTesting(5);  // ll_add -> BIEN -> error del test
	//startTesting(6);  // ll_get -> BIEN
	//startTesting(7);  // ll_set -> BIEN -> error del test
	//startTesting(8);  // ll_remove -> BIEN
	//startTesting(9);  // ll_clear -> BIEN
	//startTesting(10); // ll_deleteLinkedList -> BIEN
	//startTesting(11); // ll_indexOf -> BIEN -> error del test
	//startTesting(12); // ll_isEmpty -> BIEN
	//startTesting(13); // ll_push -> BIEN -> error del test
	//startTesting(14); // ll_pop -> BIEN
	//startTesting(15); // ll_contains -> BIEN -> error del test
	startTesting(16); // ll_containsAll -> No corre el test, ni siquiera inicia.
	//startTesting(17); // ll_subList -> BIEN
	//startTesting(18); // ll_clone -> BIEN
	//startTesting(19); // ll_sort -> BIEN?

    return 0;
}

































