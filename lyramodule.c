
/* Use this file as a template to start implementing a module that
   also declares object types. All occurrences of 'Pylyrao' should be changed
   to something reasonable for your objects. After that, all other
   occurrences of 'pylyra' should be changed to something reasonable for your
   module. If your module is named foo your sourcefile should be named
   foomodule.c.

   You will probably want to delete all references to 'x_attr' and add
   your own types of attributes instead.  Maybe you want to name your
   local variables other than 'self'.  If your object type is needed in
   other files, you'll have to create a file "foobarobject.h"; see
   intobject.h for an example. */

#include "Python.h"
#include "Lyra.h"

static PyObject *ErrorObject;

/* --------------------------------------------------------------------- */

/* Function of two integers returning integer */

PyDoc_STRVAR(pylyra_foo_doc,
"foo(i,j)\n\
\n\
Return the sum of i and j.");

static PyObject *
pylyra_foo(PyObject *self, PyObject *args)
{
	long i, j;
	long res;
	if (!PyArg_ParseTuple(args, "ll:foo", &i, &j))
		return NULL;
	res = i+j; /* PYLYRAX Do something here */
	return PyLong_FromLong(res);
}

PyDoc_STRVAR(pylyra_lyra_doc,
             "foo(i,j)\n\
\n\
Return the sum of i and j.");

static PyObject *
pylyra_lyra(PyObject *self, PyObject *args)
{
	/* long i, j; */
	/* long res; */
	/* if (!PyArg_ParseTuple(args, "ll:foo", &i, &j)) */
	/* 	return NULL; */
	/* res = i+j; /\* PYLYRAX Do something here *\/ */
	/* return PyLong_FromLong(res); */

  int kLen = 64;
  unsigned char *K = malloc(kLen);
  unsigned char *pwd;
  int pwdLen = 11;
  unsigned char *salt;
  int saltLen = 16;
  int tCost = 5;
  int nRows = 1024;
  int result;
  int countSample = 10;
  int indexSalt = 0;
  pwdLen = countSample;
  int count;
  pwd = malloc(sizeof (pwd) * pwdLen);
  for (count = 0; count < pwdLen; count++) {
    pwd[count] = count;
  }

  salt = malloc(sizeof (salt) * saltLen);
  for (count = 0; count < saltLen; count++) {
    salt[count] = saltLen * indexSalt + count;
  }
  indexSalt++;
  if (indexSalt == saltLen)
    indexSalt = 0;
 result = lyra(K, kLen, (unsigned char*) pwd, pwdLen, (unsigned char*) salt, saltLen, tCost, nRows, N_COLS);
 /* return PyLong_FromLong(result); */
 return PyBytes_FromString(K);
}


static PyTypeObject Str_Type = {
	/* The ob_type field must be initialized in the module init function
	 * to be portable to Windows without using C++. */
	PyVarObject_HEAD_INIT(NULL, 0)
	"pylyramodule.Str",		/*tp_name*/
	0,			/*tp_basicsize*/
	0,			/*tp_itemsize*/
	/* methods */
	0,			/*tp_dealloc*/
	0,			/*tp_print*/
	0,			/*tp_getattr*/
	0,			/*tp_setattr*/
	0,			/*tp_reserved*/
	0,			/*tp_repr*/
	0,			/*tp_as_number*/
	0,			/*tp_as_sequence*/
	0,			/*tp_as_mapping*/
	0,			/*tp_hash*/
	0,			/*tp_call*/
	0,			/*tp_str*/
	0,			/*tp_getattro*/
	0,			/*tp_setattro*/
	0,			/*tp_as_buffer*/
	Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
	0,			/*tp_doc*/
	0,			/*tp_traverse*/
	0,			/*tp_clear*/
	0,			/*tp_richcompare*/
	0,			/*tp_weaklistoffset*/
	0,			/*tp_iter*/
	0,			/*tp_iternext*/
	0,			/*tp_methods*/
	0,			/*tp_members*/
	0,			/*tp_getset*/
	0, /* see PyInit_pylyra */	/*tp_base*/
	0,			/*tp_dict*/
	0,			/*tp_descr_get*/
	0,			/*tp_descr_set*/
	0,			/*tp_dictoffset*/
	0,			/*tp_init*/
	0,			/*tp_alloc*/
	0,			/*tp_new*/
	0,			/*tp_free*/
	0,			/*tp_is_gc*/
};

/* ---------- */

static PyObject *
null_richcompare(PyObject *self, PyObject *other, int op)
{
	Py_INCREF(Py_NotImplemented);
	return Py_NotImplemented;
}

static PyTypeObject Null_Type = {
	/* The ob_type field must be initialized in the module init function
	 * to be portable to Windows without using C++. */
	PyVarObject_HEAD_INIT(NULL, 0)
	"pylyramodule.Null",	/*tp_name*/
	0,			/*tp_basicsize*/
	0,			/*tp_itemsize*/
	/* methods */
	0,			/*tp_dealloc*/
	0,			/*tp_print*/
	0,			/*tp_getattr*/
	0,			/*tp_setattr*/
	0,			/*tp_reserved*/
	0,			/*tp_repr*/
	0,			/*tp_as_number*/
	0,			/*tp_as_sequence*/
	0,			/*tp_as_mapping*/
	0,			/*tp_hash*/
	0,			/*tp_call*/
	0,			/*tp_str*/
	0,			/*tp_getattro*/
	0,			/*tp_setattro*/
	0,			/*tp_as_buffer*/
	Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
	0,			/*tp_doc*/
	0,			/*tp_traverse*/
	0,			/*tp_clear*/
	null_richcompare,	/*tp_richcompare*/
	0,			/*tp_weaklistoffset*/
	0,			/*tp_iter*/
	0,			/*tp_iternext*/
	0,			/*tp_methods*/
	0,			/*tp_members*/
	0,			/*tp_getset*/
	0, /* see PyInit_pylyra */	/*tp_base*/
	0,			/*tp_dict*/
	0,			/*tp_descr_get*/
	0,			/*tp_descr_set*/
	0,			/*tp_dictoffset*/
	0,			/*tp_init*/
	0,			/*tp_alloc*/
	0, /* see PyInit_pylyra */	/*tp_new*/
	0,			/*tp_free*/
	0,			/*tp_is_gc*/
};


/* ---------- */


/* List of functions defined in the module */

static PyMethodDef pylyra_methods[] = {
	{"foo",		pylyra_foo,		METH_VARARGS,
	 	pylyra_foo_doc},
  {"lyra", pylyra_lyra, METH_VARARGS,
   pylyra_lyra_doc},
	{NULL,		NULL}		/* sentinel */
};

PyDoc_STRVAR(module_doc,
"This is a template module just for instruction.");

/* Initialization function for the module (*must* be called PyInit_pylyra) */

static struct PyModuleDef pylyramodule = {
	PyModuleDef_HEAD_INIT,
	"pylyra",
	module_doc,
	-1,
	pylyra_methods,
	NULL,
	NULL,
	NULL,
	NULL
};

PyMODINIT_FUNC
PyInit_pylyra(void)
{
	PyObject *m = NULL;

	/* Due to cross platform compiler issues the slots must be filled
	 * here. It's required for portability to Windows without requiring
	 * C++. */
	Null_Type.tp_base = &PyBaseObject_Type;
	Null_Type.tp_new = PyType_GenericNew;
	Str_Type.tp_base = &PyUnicode_Type;

	/* Create the module and add the functions */
	m = PyModule_Create(&pylyramodule);
	if (m == NULL)
		goto fail;

	/* Add some symbolic constants to the module */
	if (ErrorObject == NULL) {
		ErrorObject = PyErr_NewException("pylyra.error", NULL, NULL);
		if (ErrorObject == NULL)
			goto fail;
	}
	Py_INCREF(ErrorObject);
	PyModule_AddObject(m, "error", ErrorObject);

	/* Add Str */
	if (PyType_Ready(&Str_Type) < 0)
		goto fail;
	PyModule_AddObject(m, "Str", (PyObject *)&Str_Type);

	/* Add Null */
	if (PyType_Ready(&Null_Type) < 0)
		goto fail;
	PyModule_AddObject(m, "Null", (PyObject *)&Null_Type);
	return m;
 fail:
	Py_XDECREF(m);
	return NULL;
}
