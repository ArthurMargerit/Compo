
def context_get_empty():
    context = {
        "stack_file": [],
        "message": []
    }

    return context


def context_create(main_file):
    context = context_get_empty()
    context_add_file(context, main_file)
    return context


def context_add_file(context, file_to_add):
    context["stack_file"].append(file_to_add)


def context_pop_file(context):
    context["stack_file"].pop()


def context_list_file(context):
    return context["stack_file"]
