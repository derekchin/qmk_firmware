import json

# Define the exact target labels in the desired order
ordered_labels_and_pos = [
    # L00..L05
    ("Esc", 0, 2.63, [0,0]),
    ("Q", 1.5, 2.63, [0,1]),
    ("W", 3, 1.88, [0,2]),
    ("E", 4.5, 1.75, [0,3]),
    ("R", 6, 1.88, [0,4]),
    ("T", 7.5, 2, [0,5]),
    
    # R00..R05
    ("Y", 16.25, 1.75, [4,5]),
    ("U", 17.75, 1.38, [4,4]),
    ("I", 19.25, 1, [4,3]),
    ("O", 20.75, 1.13, [4,2]),
    ("P", 22.25, 1.88, [4,1]),
    ("BackSp", 23.75, 1.88, [4,0]),
    
    # L10..L15
    ("Tab", 0, 4.13, [1,0]),
    ("A", 1.5, 4.13, [1,1]),
    ("S", 3, 3.38, [1,2]),
    ("D", 4.5, 3.25, [1,3]),
    ("F", 6, 3.38, [1,4]),
    ("G", 7.5, 3.5, [1,5]),
    
    # R10..R15
    ("H", 16.25, 3.25, [5,5]),
    ("J", 17.75, 2.88, [5,4]),
    ("K", 19.25, 2.5, [5,3]),
    ("L", 20.75, 2.63, [5,2]),
    (":", 22.25, 3.38, [5,1]),
    ("Enter", 23.75, 3.38, [5,0]),
    
    # L20..L25
    ("LCtrl", 0, 5.63, [2,0]),
    ("Z", 1.5, 5.63, [2,1]),
    ("X", 3, 4.88, [2,2]),
    ("C", 4.5, 4.75, [2,3]),
    ("V", 6, 4.88, [2,4]),
    ("B", 7.5, 5, [2,5]),
    
    # R20..R25
    ("N", 16.25, 4.75, [6,5]),
    ("M", 17.75, 4.38, [6,4]),
    ("<", 19.25, 4, [6,3]),
    (">", 20.75, 4.13, [6,2]),
    ("?", 22.25, 4.88, [6,1]),
    ("RCtrl", 23.75, 4.88, [6,0]),
    
    # L32..L35
    ("Win", 3, 6.38, [3,2]),
    ("LAlt", 4.5, 6.25, [3,3]),
    ("", 6.75, 6.88, [3,4]),
    ("Space", 8.25, 6.88, [3,5]),
    
    # R30..R33
    ("Space", 15.75, 6.63, [7,5]),
    ("", 17.25, 6.63, [7,4]),
    ("AltGr", 19.25, 5.5, [7,3]),
    ("Menu", 20.75, 5.63, [7,2]),
]

with open("/Users/derek/Downloads/qmk_firmware/keyboards/thumbs_up/info.json", "r") as f:
    data = json.load(f)

old_layout = data["layouts"]["LAYOUT"]["layout"]
new_layout = []

for label, x, y, matrix in ordered_labels_and_pos:
    # Find the exact key from old_layout
    matched_key = None
    for k in old_layout:
        if k["label"] == label and abs(k["x"] - x) < 0.1 and abs(k["y"] - y) < 0.1:
            matched_key = k
            break
    if not matched_key:
        print(f"Warning: Could not find key {label} at {x}, {y}")
        continue
    
    # Update properties
    matched_key["y"] -= 1  # subtract 1 from Y
    matched_key["matrix"] = matrix
    new_layout.append(matched_key)

if len(new_layout) == 44:
    data["layouts"]["LAYOUT"]["layout"] = new_layout
    with open("/Users/derek/Downloads/qmk_firmware/keyboards/thumbs_up/info.json", "w") as f:
        json.dump(data, f, indent=2)
    print("info.json successfully updated.")
else:
    print(f"Error: expected 44 keys, got {len(new_layout)}")

