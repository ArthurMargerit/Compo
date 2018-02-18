
def get_type_or_struct(main, key):

    if key in main["TYPES"] and key in main["STRUCTS"]:
        print("WARNING: TYPES and struct DEFINITION for ", key)

    if key in main["TYPES"]:
        return main["TYPES"][key]

    if key in main["STRUCTS"]:
        return main["STRUCTS"][key]

    print("ERROR aucun STRUCT ou TYPE  avec le nom", ">"+key+"<")


def get_interface(main, key):
    if key in main["INTERFACES"]:
        return main["INTERFACES"][key]

    print("ERROR aucun INTERFACES avec le nom", ">"+key+"<")


def get_composant(main, key):
    if key in main["COMPOSANTS"]:
        return main["COMPOSANTS"][key]

    print("ERROR aucun COMPOSANT avec le nom", ">"+key+"<")


def get_stuct(main, key):
    if key in main["STRUCTS"]:
        return main["STRUCTS"][key]

    print("ERROR aucune STRUCT avec le nom", ">"+key+"<")


def get_deploiment(main, key):
    if key in main["DEPLOIMENTS"]:
        return main["DEPLOIMENTS"][key]

    print("ERROR aucune DEPLOIEMENT avec le nom", ">"+key+"<")


def get_empty_main():

    main = {
        "INCLUDES": {},
        "TYPES": {},
        "STRUCTS": {},
        "INTERFACES": {},
        "COMPOSANTS": {},
        "DEPLOIMENTS": {}
    }

    return main
