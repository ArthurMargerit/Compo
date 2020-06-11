# This file was automatically generated by SWIG (http://www.swig.org).
# Version 4.0.1
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.

from sys import version_info as _swig_python_version_info
if _swig_python_version_info < (2, 7, 0):
    raise RuntimeError("Python 2.7 or later required")

# Import the low-level C/C++ module
if __package__ or "." in __name__:
    from . import _Struct
else:
    import _Struct

try:
    import builtins as __builtin__
except ImportError:
    import __builtin__

def _swig_repr(self):
    try:
        strthis = "proxy of " + self.this.__repr__()
    except __builtin__.Exception:
        strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)


def _swig_setattr_nondynamic_instance_variable(set):
    def set_instance_attr(self, name, value):
        if name == "thisown":
            self.this.own(value)
        elif name == "this":
            set(self, name, value)
        elif hasattr(self, name) and isinstance(getattr(type(self), name), property):
            set(self, name, value)
        else:
            raise AttributeError("You cannot add instance attributes to %s" % self)
    return set_instance_attr


def _swig_setattr_nondynamic_class_variable(set):
    def set_class_attr(cls, name, value):
        if hasattr(cls, name) and not isinstance(getattr(cls, name), property):
            set(cls, name, value)
        else:
            raise AttributeError("You cannot add class attributes to %s" % cls)
    return set_class_attr


def _swig_add_metaclass(metaclass):
    """Class decorator for adding a metaclass to a SWIG wrapped class - a slimmed down version of six.add_metaclass"""
    def wrapper(cls):
        return metaclass(cls.__name__, cls.__bases__, cls.__dict__.copy())
    return wrapper


class _SwigNonDynamicMeta(type):
    """Meta class to enforce nondynamic attributes (no new attributes) for a class"""
    __setattr__ = _swig_setattr_nondynamic_class_variable(type.__setattr__)


class Serializable_Item(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")

    def __init__(self, *args, **kwargs):
        raise AttributeError("No constructor defined - class is abstract")
    __repr__ = _swig_repr

    def to_stream(self, arg2, arg3):
        return _Struct.Serializable_Item_to_stream(self, arg2, arg3)

    def from_stream(self, _is, p_ctx):
        return _Struct.Serializable_Item_from_stream(self, _is, p_ctx)

    def __str__(self):
        return _Struct.Serializable_Item___str__(self)
    __swig_destroy__ = _Struct.delete_Serializable_Item

# Register Serializable_Item in _Struct:
_Struct.Serializable_Item_swigregister(Serializable_Item)

class Serialization_context_import(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr

    def __init__(self):
        _Struct.Serialization_context_import_swiginit(self, _Struct.new_Serialization_context_import())
    __swig_destroy__ = _Struct.delete_Serialization_context_import

    def import_wanted(self, os):
        return _Struct.Serialization_context_import_import_wanted(self, os)

    def get_loc(self, *args):
        return _Struct.Serialization_context_import_get_loc(self, *args)

    def is_wanted_loc(self, arg2):
        return _Struct.Serialization_context_import_is_wanted_loc(self, arg2)

    def is_wanted_loc_sp(self, p_ext):
        return _Struct.Serialization_context_import_is_wanted_loc_sp(self, p_ext)

    def inscribe(self, p_ext, p_loc):
        return _Struct.Serialization_context_import_inscribe(self, p_ext, p_loc)

    def is_inscribe(self, p_ext):
        return _Struct.Serialization_context_import_is_inscribe(self, p_ext)

# Register Serialization_context_import in _Struct:
_Struct.Serialization_context_import_swigregister(Serialization_context_import)

class Serialization_context_export(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr

    def __init__(self):
        _Struct.Serialization_context_export_swiginit(self, _Struct.new_Serialization_context_export())
    __swig_destroy__ = _Struct.delete_Serialization_context_export

    def export_wanted(self, os):
        return _Struct.Serialization_context_export_export_wanted(self, os)

    def want(self, arg2):
        return _Struct.Serialization_context_export_want(self, arg2)

    def declare(self, arg2):
        return _Struct.Serialization_context_export_declare(self, arg2)

    def is_declare(self, arg2):
        return _Struct.Serialization_context_export_is_declare(self, arg2)

    def is_wanted(self, arg2):
        return _Struct.Serialization_context_export_is_wanted(self, arg2)

# Register Serialization_context_export in _Struct:
_Struct.Serialization_context_export_swigregister(Serialization_context_export)


def get_type(_is):
    return _Struct.get_type(_is)

def get_addr(_is):
    return _Struct.get_addr(_is)

def get_word(_is, one_of):
    return _Struct.get_word(_is, one_of)

def to_pointer(ptr):
    return _Struct.to_pointer(ptr)

def p_to_stream(*args):
    return _Struct.p_to_stream(*args)

def p_from_stream(*args):
    return _Struct.p_from_stream(*args)

def stream_me_out(*args):
    return _Struct.stream_me_out(*args)

def steam_me_in(*args):
    return _Struct.steam_me_in(*args)
class Serializable_fac(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")

    def __init__(self, *args, **kwargs):
        raise AttributeError("No constructor defined")
    __repr__ = _swig_repr

    @staticmethod
    def get_inst():
        return _Struct.Serializable_fac_get_inst()

    def build(self, p_type, p_stream, arg4):
        return _Struct.Serializable_fac_build(self, p_type, p_stream, arg4)

    def build_sp(self, p_type, p_stream):
        return _Struct.Serializable_fac_build_sp(self, p_type, p_stream)

    def subscribe(self, ss, v, v_sp):
        return _Struct.Serializable_fac_subscribe(self, ss, v, v_sp)

# Register Serializable_fac in _Struct:
_Struct.Serializable_fac_swigregister(Serializable_fac)

def Serializable_fac_get_inst():
    return _Struct.Serializable_fac_get_inst()

class Struct(Serializable_Item):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")

    def __init__(self, *args, **kwargs):
        raise AttributeError("No constructor defined - class is abstract")
    __repr__ = _swig_repr
    __swig_destroy__ = _Struct.delete_Struct

# Register Struct in _Struct:
_Struct.Struct_swigregister(Struct)



