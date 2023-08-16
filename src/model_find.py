

def type_find(main, name):
    type = main["TYPES"][name]

    # STRUCT CHECK
    use_by_structs = []
    for strut in main["STRUCTS"]:
        append = False
        for d in strut["DATA"]:
            if d["TYPE"] == type:
                append = True
        if append:
            use_by_structs.append(struct)

    # INTERFACE
    use_by_interface = []
    for interface in main["INTERFACES"]:
        append = False
        for d in interface["DATA"]:
            if d["TYPE"] == type:
                append = True
            elif "DATA" in d["TYPE"]:
                pass

        for d in interface["FUNCTION"]:
            if d["RETURN"] == type:
                append = true

            for si in d["SIGNATURE"]:
                if si["TYPE"] == type:
                    append = true

        if append:
            use_by_structs.append(struct)

    return {"USE_BY": main["TYPES"],
            "RESULT": main["TYPES"][data]}


def struct_find(main, data):
    pass


def interface_find(main, data):
    pass


def composant_find(main, data):
    pass


def deployment_find(main, data):
    pass
