self.onmessage = async function(e){

    try{

        const response = await fetch(e.data);

        if(!response.ok){
            throw new Error("Failed to fetch users");
        }

        const data = await response.json();

        const users = data.users;

        if(!users || users.length===0){
            self.postMessage([]);
            return;
        }

        const result = users.map(user=>({
            name:`${user.firstName} ${user.lastName}`,
            status: Math.random()>0.5 ? "Active" : "Inactive"
        }));

        self.postMessage(result);

    }
    catch(err){
        self.postMessage([]);
    }

}