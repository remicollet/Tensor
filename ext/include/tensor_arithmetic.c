#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "kernel/operators.h"

void tensor_multiply(zval * return_value, zval * a, zval * b)
{
    int i;
    double product;
	zval c;

    zend_array * aHat = Z_ARR_P(a);
    zend_array * bHat = Z_ARR_P(b);

    Bucket * va = aHat->arData;
    Bucket * vb = bHat->arData;

    int n = zend_array_count(aHat);

	array_init_size(&c, n);

    for (i = 0; i < n; i++) {
        product = zephir_get_doubleval(&va[i].val) * zephir_get_doubleval(&vb[i].val);

	    add_next_index_double(&c, product);
    }

    RETVAL_ARR(Z_ARR(c));
}

void tensor_divide(zval * return_value, zval * a, zval * b)
{
    int i;
    double quotient;
	zval c;

    zend_array * aHat = Z_ARR_P(a);
    zend_array * bHat = Z_ARR_P(b);

    Bucket * va = aHat->arData;
    Bucket * vb = bHat->arData;

    int n = zend_array_count(aHat);

	array_init_size(&c, n);

    for (i = 0; i < n; i++) {
        quotient = zephir_get_doubleval(&va[i].val) / zephir_get_doubleval(&vb[i].val);

	    add_next_index_double(&c, quotient);
    }

    RETVAL_ARR(Z_ARR(c));
}

void tensor_add(zval * return_value, zval * a, zval * b)
{
    int i;
    double sum;
	zval c;

    zend_array * aHat = Z_ARR_P(a);
    zend_array * bHat = Z_ARR_P(b);

    Bucket * va = aHat->arData;
    Bucket * vb = bHat->arData;

    int n = zend_array_count(aHat);

	array_init_size(&c, n);

    for (i = 0; i < n; i++) {
        sum = zephir_get_doubleval(&va[i].val) + zephir_get_doubleval(&vb[i].val);

	    add_next_index_double(&c, sum);
    }

    RETVAL_ARR(Z_ARR(c));
}

void tensor_subtract(zval * return_value, zval * a, zval * b)
{
    int i;
    double difference;
	zval c;

    zend_array * aHat = Z_ARR_P(a);
    zend_array * bHat = Z_ARR_P(b);

    Bucket * va = aHat->arData;
    Bucket * vb = bHat->arData;

    int n = zend_array_count(aHat);

	array_init_size(&c, n);

    for (i = 0; i < n; i++) {
        difference = zephir_get_doubleval(&va[i].val) - zephir_get_doubleval(&vb[i].val);

	    add_next_index_double(&c, difference);
    }

    RETVAL_ARR(Z_ARR(c));
}

void tensor_pow(zval * return_value, zval * a, zval * b)
{
    int i;
    double power;
	zval c;

    zend_array * aHat = Z_ARR_P(a);
    zend_array * bHat = Z_ARR_P(b);

    Bucket * va = aHat->arData;
    Bucket * vb = bHat->arData;

    int n = zend_array_count(aHat);

	array_init_size(&c, n);

    for (i = 0; i < n; i++) {
        power = pow(zephir_get_doubleval(&va[i].val), zephir_get_doubleval(&vb[i].val));

	    add_next_index_double(&c, power);
    }

    RETVAL_ARR(Z_ARR(c));
}

void tensor_mod(zval * return_value, zval * a, zval * b)
{
    int i;
    zval modulus;
	zval c;

    zend_array * aHat = Z_ARR_P(a);
    zend_array * bHat = Z_ARR_P(b);

    Bucket * va = aHat->arData;
    Bucket * vb = bHat->arData;

    int n = zend_array_count(aHat);

	array_init_size(&c, n);

    for (i = 0; i < n; i++) {
        mod_function(&modulus, &va[i].val, &vb[i].val);

	    add_next_index_zval(&c, &modulus);
    }

    RETVAL_ARR(Z_ARR(c));
}

void tensor_multiply_scalar(zval * return_value, zval * a, zval * b)
{
    int i;
    double product;
	zval c;

    zend_array * aHat = Z_ARR_P(a);

    Bucket * va = aHat->arData;

    double bHat = zephir_get_doubleval(b);

    int n = zend_array_count(aHat);

	array_init_size(&c, n);

    for (i = 0; i < n; i++) {
        product = zephir_get_doubleval(&va[i].val) * bHat;

	    add_next_index_double(&c, product);
    }

    RETVAL_ARR(Z_ARR(c));
}

void tensor_divide_scalar(zval * return_value, zval * a, zval * b)
{
    int i;
    double quotient;
	zval c;

    zend_array * aHat = Z_ARR_P(a);

    Bucket * va = aHat->arData;

    double bHat = zephir_get_doubleval(b);

    int n = zend_array_count(aHat);

	array_init_size(&c, n);

    for (i = 0; i < n; i++) {
        quotient = zephir_get_doubleval(&va[i].val) / bHat;

	    add_next_index_double(&c, quotient);
    }

    RETVAL_ARR(Z_ARR(c));
}

void tensor_add_scalar(zval * return_value, zval * a, zval * b)
{
    int i;
    double sum;
	zval c;

    zend_array * aHat = Z_ARR_P(a);

    Bucket * va = aHat->arData;

    double bHat = zephir_get_doubleval(b);

    int n = zend_array_count(aHat);

	array_init_size(&c, n);

    for (i = 0; i < n; i++) {
        sum = zephir_get_doubleval(&va[i].val) + bHat;

	    add_next_index_double(&c, sum);
    }

    RETVAL_ARR(Z_ARR(c));
}

void tensor_subtract_scalar(zval * return_value, zval * a, zval * b)
{
    int i;
    double difference;
	zval c;

    zend_array * aHat = Z_ARR_P(a);

    Bucket * va = aHat->arData;

    double bHat = zephir_get_doubleval(b);

    int n = zend_array_count(aHat);

	array_init_size(&c, n);

    for (i = 0; i < n; i++) {
        difference = zephir_get_doubleval(&va[i].val) - bHat;

	    add_next_index_double(&c, difference);
    }

    RETVAL_ARR(Z_ARR(c));
}

void tensor_pow_scalar(zval * return_value, zval * a, zval * b)
{
    int i;
    double power;
	zval c;

    zend_array * aHat = Z_ARR_P(a);

    Bucket * va = aHat->arData;

    double bHat = zephir_get_doubleval(b);

    int n = zend_array_count(aHat);

	array_init_size(&c, n);

    for (i = 0; i < n; i++) {
        power = pow(zephir_get_doubleval(&va[i].val), bHat);

	    add_next_index_double(&c, power);
    }

    RETVAL_ARR(Z_ARR(c));
}

void tensor_mod_scalar(zval * return_value, zval * a, zval * b)
{
    int i;
    zval modulus;
	zval c;

    zend_array * aHat = Z_ARR_P(a);

    Bucket * va = aHat->arData;

    int n = zend_array_count(aHat);

	array_init_size(&c, n);

    for (i = 0; i < n; i++) {
        mod_function(&modulus, &va[i].val, b);

	    add_next_index_zval(&c, &modulus);
    }

    RETVAL_ARR(Z_ARR(c));
}
