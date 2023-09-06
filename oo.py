def create_html_from_text(input_file):
    html_template = """<!DOCTYPE html><html><head> <title>Pagina generata da testo</title> <style>.container { position: relative;width: 500px; height: 500px;border: 1px solid black;}.component {position: absolute;border: 1px solid red;background-color: lightgray;padding: 10px;}</style></head><body><div class="container">{{components}}</div></body></html>"""

    components = ""

    with open(input_file, "r") as f:
        lines = f.readlines()
        for line in lines:
            parts = line.strip().split()
            component_name = parts[0]
            left = parts[1]
            top = parts[2]
            components += f'<div class="component" style="left: {left}px; top: {top}px;">{component_name}</div>\n'

    html_content = html_template.format(components=components)

    with open("output.html", "w") as output_file:
        output_file.write(html_content)

create_html_from_text("prova.map")
