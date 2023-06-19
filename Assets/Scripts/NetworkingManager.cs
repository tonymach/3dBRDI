//using System.Collections;
//using System.Collections.Generic;
//using UnityEngine;
//using UnityEngine.Networking;

//public class NetworkManager : MonoBehaviour
//{
//    private static NetworkManager _instance;

//    public static NetworkManager Instance
//    {
//        get
//        {
//            if (_instance == null)
//            {
//                _instance = FindObjectOfType<NetworkManager>();

//                if (_instance == null)
//                {
//                    Debug.LogError("No instance of NetworkManager found in the scene.");
//                }
//            }
//            return _instance;
//        }
//    }

//    void Start()
//    {
//        Debug.Log("NetworkManager has started");
//    }

//    private IEnumerator SendObjectPathData(int trial, string condition, string participantId, List<SpawnObjectOnTrigger.ObjectPathData> objectPath)
//    {
//        // Create lists to hold the x, y, and z positions
//        List<float> x_positions = new List<float>();
//        List<float> y_positions = new List<float>();
//        List<float> z_positions = new List<float>();

//        // Populate the position lists
//        foreach (SpawnObjectOnTrigger.ObjectPathData pathData in objectPath)
//        {
//            x_positions.Add(pathData.position.x);
//            y_positions.Add(pathData.position.y);
//            z_positions.Add(pathData.position.z);
//        }

//        // Create a dictionary to hold the data
//        Dictionary<string, object> data = new Dictionary<string, object>();
//        data.Add("trial", trial);
//        data.Add("condition", condition);
//        data.Add("participantId", participantId);
//        data.Add("x_positions", x_positions);
//        data.Add("y_positions", y_positions);
//        data.Add("z_positions", z_positions);

//        // Convert the data to JSON
//        string json = JsonUtility.ToJson(data);

//        // Create a new UnityWebRequest and assign the target URL
//        WWWForm form = new WWWForm();
//        form.AddField("trial", trial);
//        form.AddField("condition", condition);
//        form.AddField("participantId", participantId);
//        form.AddField("x_positions", JsonUtility.ToJson(x_positions));
//        form.AddField("y_positions", JsonUtility.ToJson(y_positions));
//        form.AddField("z_positions", JsonUtility.ToJson(z_positions));

//        using (UnityWebRequest www = UnityWebRequest.Post("http://192.168.0.104:5001/postdata", form))
//        {
//            yield return www.SendWebRequest();

//            if (www.result == UnityWebRequest.Result.ConnectionError || www.result == UnityWebRequest.Result.ProtocolError)
//            {
//                Debug.LogError(www.error);
//            }
//            else
//            {
//                Debug.Log("Response: " + www.downloadHandler.text);
//            }
//        }
//    }

//public void StartSendObjectPathData(int trial, string condition, string participantId, List<SpawnObjectOnTrigger.ObjectPathData> objectPath)
//    {
//        StartCoroutine(SendObjectPathData(trial, condition, participantId, objectPath));
//    }
//}
