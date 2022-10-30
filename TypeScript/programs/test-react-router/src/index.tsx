import React from "react";
import ReactDOM from "react-dom/client";
import {
  BrowserRouter, Routes, Route,
  Outlet, Link, useSearchParams,
  useNavigate
} from "react-router-dom";

const NavBar = () => {
  return (
    <>
      <nav>
        <ul>
          <li>
            <Link to="/">Home</Link>
          </li>
          <li>
            <Link to="/login">Login</Link>
          </li>
          <li>
            <Link to="/files">Files</Link>
          </li>
        </ul>
      </nav>

      <Outlet />
    </>
  )
};

const Home = () => {
  return <h1>Home</h1>;
};

const Login = () => {
  const navigate = useNavigate();

  const [count, setCount] = React.useState<number>(0);

  const increment = () => {
    setCount(count + 1);
  }

  const [username, setUsername] = React.useState<string>("");
  const [password, setPassword] = React.useState<string>("");

  
  return (
    <div>
      <h1>Login page - {count}</h1>
      <button onClick={increment}>Increment</button>
      <Link to={{
        pathname: "/files",
        search: `?f=${count}`
      }}>Go to files</Link>

      <input type={"email"} placeholder={"Username"} onChange={(event) => setUsername(event.target.value)}></input>
      <input type={"password"} placeholder={"Password"} onChange={(event) => setPassword(event.target.value)}></input>
      <button
      onClick={
        () => navigate({
          pathname: "/files",
          search: `?f=User:${username.replaceAll(" ", "+")}+,+Pass:${password.replaceAll(" ", "+")}`
        })
      }
      
      onContextMenu={
        () => alert(`User: ${username}\nPass: ${password}`)
      }
      >Login!</button>
    </div>
  );
};

const Files = () => {
  const [searchParams, setSearchParams] = useSearchParams();

  if(!searchParams.has("f")) {
    setSearchParams({
      f: "Not set"
    });
  }

  return (
    <div>
      <h1>Login page</h1>
      <p>Current folder: {searchParams.get("f")}</p>
    </div>
  );
};

const NoPage = () => {
  return <h1>404</h1>;
};

export default function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<NavBar />}>

        <Route index element={<Home />} />
        <Route path="login" element={<Login />} />
        <Route path="files" element={<Files />} />
        <Route path="*" element={<NoPage />} />
        </Route>
      </Routes>
    </BrowserRouter>
  );
}

const root = ReactDOM.createRoot(document.getElementById('root') as HTMLElement);
root.render(<App />);

