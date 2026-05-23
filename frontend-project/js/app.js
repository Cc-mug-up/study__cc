(function () {
  "use strict";

  const STORAGE_KEY = "task-manager-tasks";

  // DOM elements
  const taskForm = document.getElementById("taskForm");
  const taskInput = document.getElementById("taskInput");
  const taskList = document.getElementById("taskList");
  const emptyState = document.getElementById("emptyState");
  const actionsBar = document.getElementById("actionsBar");
  const clearCompletedBtn = document.getElementById("clearCompleted");
  const taskCount = document.getElementById("taskCount");
  const filterBtns = document.querySelectorAll(".filter-btn");

  let tasks = [];
  let currentFilter = "all";

  // --- Storage ---
  function loadTasks() {
    try {
      const raw = localStorage.getItem(STORAGE_KEY);
      tasks = raw ? JSON.parse(raw) : [];
    } catch {
      tasks = [];
    }
  }

  function saveTasks() {
    localStorage.setItem(STORAGE_KEY, JSON.stringify(tasks));
  }

  // --- Render ---
  function render() {
    const filtered = tasks.filter(function (task) {
      if (currentFilter === "active") return !task.completed;
      if (currentFilter === "completed") return task.completed;
      return true;
    });

    taskList.innerHTML = "";

    if (filtered.length === 0) {
      emptyState.classList.remove("hidden");
      taskList.style.display = "none";
    } else {
      emptyState.classList.add("hidden");
      taskList.style.display = "";
    }

    filtered.forEach(function (task) {
      var li = document.createElement("li");
      li.className = "task-item" + (task.completed ? " completed" : "");
      li.dataset.id = task.id;

      var checkbox = document.createElement("div");
      checkbox.className = "task-checkbox" + (task.completed ? " checked" : "");
      checkbox.addEventListener("click", function () {
        toggleTask(task.id);
      });

      var span = document.createElement("span");
      span.className = "task-text";
      span.textContent = task.text;

      var delBtn = document.createElement("button");
      delBtn.className = "task-delete";
      delBtn.innerHTML = "&times;";
      delBtn.title = "删除";
      delBtn.addEventListener("click", function () {
        deleteTask(task.id);
      });

      li.appendChild(checkbox);
      li.appendChild(span);
      li.appendChild(delBtn);
      taskList.appendChild(li);
    });

    updateStats();
  }

  function updateStats() {
    var activeCount = tasks.filter(function (t) {
      return !t.completed;
    }).length;
    taskCount.textContent = activeCount + " 个任务";

    var hasCompleted = tasks.some(function (t) {
      return t.completed;
    });
    actionsBar.style.display = hasCompleted ? "" : "none";
  }

  // --- Actions ---
  function addTask(text) {
    var trimmed = text.trim();
    if (!trimmed) return;

    tasks.unshift({
      id: Date.now().toString(36) + Math.random().toString(36).slice(2, 7),
      text: trimmed,
      completed: false,
    });

    saveTasks();
    render();
    taskInput.value = "";
    taskInput.focus();
  }

  function toggleTask(id) {
    var task = tasks.find(function (t) {
      return t.id === id;
    });
    if (task) {
      task.completed = !task.completed;
      saveTasks();
      render();
    }
  }

  function deleteTask(id) {
    tasks = tasks.filter(function (t) {
      return t.id !== id;
    });
    saveTasks();
    render();
  }

  function clearCompleted() {
    tasks = tasks.filter(function (t) {
      return !t.completed;
    });
    saveTasks();
    render();
  }

  function setFilter(filter) {
    currentFilter = filter;
    filterBtns.forEach(function (btn) {
      btn.classList.toggle("active", btn.dataset.filter === filter);
    });
    render();
  }

  // --- Events ---
  taskForm.addEventListener("submit", function (e) {
    e.preventDefault();
    addTask(taskInput.value);
  });

  clearCompletedBtn.addEventListener("click", clearCompleted);

  filterBtns.forEach(function (btn) {
    btn.addEventListener("click", function () {
      setFilter(btn.dataset.filter);
    });
  });

  // --- Init ---
  loadTasks();
  render();
})();