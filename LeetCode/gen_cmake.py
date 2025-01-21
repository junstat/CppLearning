import os


def list_all_files(directory):
    with open(f"{directory}/{directory}.cmake", "w") as f:
        for root, dirs, files in os.walk(directory):
            for file in files:
                file_full_path = os.path.join(root, file)
                if ".cmake" in file_full_path:
                    continue
                parts = file_full_path.split("\\")
                parts[0] = "list(APPEND SOURCES ${CMAKE_CURRENT_LIST_DIR}"
                line = "/".join(parts) + ")"
                f.write(line)
                f.write("\n")


def create_question_dir(parent_dir, questions):
    for question in questions:
        question_dir = f"{parent_dir}/Q{question}"
        if os.path.exists(question_dir):
            continue
        os.makedirs(question_dir, exist_ok=True)
        with open(f"{question_dir}/Solution.cpp", "w", encoding="UTF-8") as f:
            f.write("class Solution {\n")
            f.write("public:\n\n")
            f.write("};")
    list_all_files(parent_dir)


if __name__ == '__main__':
    list_all_files("Q0299")
    # create_question_dir("Q0399", [
    # '0208', '0209',
    # '0211', '0213', '0214', '0217', '0218', '0219',
    # '0220', '0221', '0222', '0223', '0224', '0227',
    # '0228', '0229', '0231', '0233', '0241', '0242',
    # '0257', '0258', '0260', '0263', '0264', '0268',
    # '0273', '0274', '0275', '0278', '0279', '0282',
    # '0284', '0287', '0289', '0290', '0295', '0297',
    # '0300', '0301', '0304', '0306', '0307', '0309',
    # '0312', '0313', '0315', '0316', '0318', '0319',
    # '0321', '0324', '0326', '0327', '0329', '0330',
    # '0332', '0334', '0335', '0336', '0337', '0338',
    # '0341', '0342', '0344', '0345', '0347', '0349',
    # '0350', '0352', '0354', '0355', '0357', '0363',
    # '0365', '0367', '0368', '0371', '0372', '0373',
    # '0374', '0375', '0376', '0377', '0378', '0380',
    # '0381', '0382', '0383', '0384', '0385', '0386',
    # '0387', '0388', '0389', '0390', '0391', '0392',
    # '0393', '0394', '0395', '0396', '0397', '0398', '0399'
    # ])
