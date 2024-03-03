use std::io::{self, Write};

struct TodoList {
    tasks: Vec<String>,
}

impl TodoList {
    fn new() -> TodoList {
        TodoList { tasks: Vec::new() }
    }

    fn add_task(&mut self, task: String) {
        self.tasks.push(task);
    }

    fn remove_task(&mut self, index: usize) -> Option<String> {
        if index < self.tasks.len() {
            Some(self.tasks.remove(index))
        } else {
            None
        }
    }

    fn list_tasks(&self) {
        if self.tasks.is_empty() {
            println!("Your to-do list is empty!");
        } else {
            println!("Your to-do list:");
            for (index, task) in self.tasks.iter().enumerate() {
                println!("{}: {}", index + 1, task);
            }
        }
    }
}

fn main() {
    let mut todo_list = TodoList::new();
    loop {
        println!("What would you like to do?");
        println!("1. Add a task");
        println!("2. Remove a task");
        println!("3. List tasks");
        println!("4. Exit");

        print!("Enter your choice: ");
        io::stdout().flush().unwrap();

        let mut choice = String::new();
        io::stdin().read_line(&mut choice).expect("Failed to read line");
        let choice: u32 = match choice.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        match choice {
            1 => {
                print!("Enter the task to add: ");
                io::stdout().flush().unwrap();
                let mut task = String::new();
                io::stdin().read_line(&mut task).expect("Failed to read line");
                todo_list.add_task(task.trim().to_string());
            }
            2 => {
                print!("Enter the index of the task to remove: ");
                io::stdout().flush().unwrap();
                let mut index_str = String::new();
                io::stdin().read_line(&mut index_str).expect("Failed to read line");
                let index: usize = match index_str.trim().parse::<usize>() {
                    Ok(num) => num - 1,
                    Err(_) => continue,
                };
                if let Some(task) = todo_list.remove_task(index) {
                    println!("Removed task: {}", task);
                } else {
                    println!("Invalid index!");
                }
            }
            3 => {
                todo_list.list_tasks();
            }
            4 => {
                println!("Exiting...");
                break;
            }
            _ => {
                println!("Invalid choice! Please enter a number between 1 and 4.");
            }
        }
    }
}
