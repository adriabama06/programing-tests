package es.lobby.events;

import es.lobby.Main;
import es.lobby.Util;
import es.lobby.config.Config;
import es.lobby.items.ItemMannager;
import org.bukkit.Bukkit;
import org.bukkit.Location;
import org.bukkit.configuration.file.FileConfiguration;
import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.player.PlayerJoinEvent;
import org.bukkit.event.player.PlayerTeleportEvent;

public class JoinListener implements Listener {
    private Main plugin;

    public JoinListener(Main plugin) {
        this.plugin = plugin;

        plugin.getServer().getPluginManager().registerEvents(this, plugin);
    }

    @EventHandler
    public void onJoin(PlayerJoinEvent event) {
        event.setJoinMessage(null);
        Player JPlayer = event.getPlayer();

        String world = Config.GetLocations().getString("lobby.world");
        if(!(world == null)) {
            FileConfiguration locs = Config.GetLocations();
            double x = locs.getDouble("lobby.x");
            double y = locs.getDouble("lobby.y");
            double z = locs.getDouble("lobby.z");
            float yaw = Float.parseFloat(locs.getString("lobby.yaw"));
            float pitch = Float.parseFloat(locs.getString("lobby.pitch"));
            JPlayer.teleport(new Location(Bukkit.getWorld(world), x, y, z, yaw, pitch), PlayerTeleportEvent.TeleportCause.PLUGIN);
        }
        // https://proxy.spigotmc.org/3d5ceb0e4998f49be1771df5d1bb62d6c68ebb41?url=https%3A%2F%2Fbugs.mojang.com%2Fsecure%2Fattachment%2F61101%2FItems_slot_number.jpg
        JPlayer.getInventory().clear();
        JPlayer.getInventory().setItem(Config.GetItems().getInt("menu_de_juegos.slot") - 1, ItemMannager.menu_de_juegos);
        JPlayer.sendMessage(Util.color(Config.GetMessages().getString("join").replace("%player%", JPlayer.getDisplayName())));
        for (Player p : Bukkit.getServer().getOnlinePlayers()) {
            if(p.getName().equals(JPlayer.getName())) {
                continue;
            }
            p.sendMessage(Util.color(Config.GetMessages().getString("public-join").replace("%player%", JPlayer.getDisplayName())));
        }
    }
}